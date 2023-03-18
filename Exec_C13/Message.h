#ifndef __MESSAGE_H__
#define __MESSAGE_H__

#include <set>
#include <string>
#include "Folder.h"

using namespace std;

class Folder;


class Message
{
friend class Folder;
friend void swap(Message &, Message &);

public:

    // 创建
    explicit Message(const string &s=""):message(s) {}
    Message(const Message &message);
    Message& operator=(const Message &);
    Message(Message &&);
    Message& operator=(Message &&);

    void save(Folder &folder) {belongFolder.insert(&folder); folder.addMsg(this);}
    void remove(Folder &folder) {belongFolder.erase(&folder); folder.removeMsg(this);}


    ~Message();

    void debug_print();

private:
    set<Folder*> belongFolder;
    string message;

    void addToFolders(const Message &msg);
    void moveFolders(Message *);
    
    void removeFromFolders();
};


inline Message::Message(const Message &message):message(message.message), belongFolder(belongFolder){for(auto ele:belongFolder){ele->addMsg(this);}}

inline Message &Message::operator=(const Message &msg){removeFromFolders();message = msg.message; addToFolders(msg); return *this;}

inline Message &Message::operator=(Message &&msg)
{
    if(this != &msg)
    {
        removeFromFolders();
        message = std::move(rhs.message);
        moveFolders(&msg);
    }
    return *this;
}

inline Message::Message(Message &&msg):message(std::move(msg.message)) {moveFolders(&msg);}

void Message::moveFolders(Message *msg)
{
    belongFolder = std::move(msg->belongFolder);
    for(auto folder:belongFolder)
    {
        folder->removeMsg(msg);
        folder->addMsg(this);   
    }
    msg->belongFolder.clear();
}

inline Message::~Message(){removeFromFolders();}

inline void Message::addToFolders(const Message &msg){for(auto ele:msg.belongFolder){ele->addMsg(this);}}

inline void Message::removeFromFolders(){for(auto ele:belongFolder){ele->removeMsg(this);}}

void swap(Message &lmsg, Message &rmsg) 
{
    for(auto ele:lmsg.belongFolder)
    {
        ele->removeMsg(&lmsg);
    }

    for(auto ele:rmsg.belongFolder)
    {
        ele->removeMsg(&rmsg);
    }

    using std::swap; 
    swap(lmsg.belongFolder, rmsg.belongFolder);
    swap(lmsg.message, rmsg.message); 
    for(auto ele:lmsg.belongFolder)
    {
        ele->addMsg(&lmsg);
    }
    
    for(auto ele:rmsg.belongFolder)
    {
        ele->addMsg(&rmsg);
    }
}


void Message::debug_print()
{
    cerr << "Message:\n\t" << message << endl;
    cerr << "Appears in " << belongFolder.size() << " Folders" << endl;
}

#endif