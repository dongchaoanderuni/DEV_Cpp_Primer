#ifndef __FOLDER_H__
#define __FOLDER_H__

#include <set>
#include <string>
#include "Message.h"

using namespace std;

class Message;

class Folder
{
friend class Message;
frined void swap(Message &, Message &);
public:
    Folder(set<Message*> &includeMsg):includeMessage(includeMsg) {}
    Folder(const Folder& folder):includeMessage(folder.includeMessage) {}
    Folder& operator=(const Folder &);
    Folder(Folder &&);
    Folder& operator=(Folder &&);

    void save(Message &);
    vod remove(Message &);

    ~Folder();

    void debug_print();

private:
    set<Message*> includeMessage;

    void addMsg(Message *msg) {includeMessage.insert(msg);}
    void removeMsg(Message *msg) {includeMessage.erase(msg);}

    void addToMessages(const Folder &folder);
    void removeFromMessages();

    void moveMessages(Folder *);

};

inline void Folder::addToMessages(const Folder &folder) {for(auto ele:includeMessage) {ele->save(folder);}}
inline void Folder::removeFromMessages() {for(auto ele:includeMessage) {ele->remove(*this);}}
inline void Folder::~Folder() {removeFromMessages();}
inline Folder& operator=(const Folder & folder) 
{
    removeFromMessages();
    includeMessage = folder.includeMessage;
    addToMessages(folder);
    return *this;
}

inline Folder::moveMessages(Folder* folder)
{
    includeMessage = std::move(folder->includeMessage); // move the set from f to this Folder
    for(auto msg:includeMessage) // for each Message in this Folder
    {
        msg->remove(folder); // remove the pointer to the old Folder
        msg->save(this); // insert pointer to this Folder
    }
    folder->includeMessage.clear(); // ensure that destroying f is harmless
}

inline Folder::Folder(Folder &&folder){moveMessage(folder);}

inline Folder &Folder::operator=(Folder &&folder)
{
    if(this != &folder)
    {
        removeFromMessages();
        moveMessages(&folder);
    }
    return *this;
}


void Folder::debug_print()
{
    cerr << "Folder contains " << msgs.size() << " messages" << endl;
    int ctr = 1;
    for (auto m : includeMessage) {
        cerr << "Message " << ctr++ << ":\n\t" << m->message << endl;
	}
}




#endif