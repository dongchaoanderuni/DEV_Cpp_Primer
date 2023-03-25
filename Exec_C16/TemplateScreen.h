#ifndef __TEMPLATESCREEN_H__
#define __TEMPLATESCREEN_H__

using namespace std;

template <int H, int W> 
class Screen;

template <int H, int W>
std::istream& operator>>(std::istream&, Screen<H,W>&);

template <int H, int W>
std::ostream& operator<<(std::ostream&, const Screen<H, W>&);

template <int H, int W>
class Screen
{
friend std::istream &operator>> <H,W>(std::istream&, Screen<H,W>&);
friend std::ostream &operator<< <H,W>(std::ostream&, const Screen<H, W>&);
public:    
    Screen(char c=' '):contents(H * W , c) {}
    char get() const {return contents[cursor];}
    char get(int, int) const;
    Screen &set(char);
    Screen &set(int, int, char);
    Screen &clear(char = bkrground);
    Screen &move(int , int);
    Screen &display(std::ostream &os) { do_display(os); return *this;}
    const Screen &display(std::ostream &os) const {do_display(os); return *this;}

private:
    void do_display(std::ostream &os) const {os << contents;}    
    int cursor = 0;
    std::string contents;
    static const char bkrground = ' ';
};

template <int H, int W>
Screen<H, W> &Screen<H,W>::clear(char c)
{
    contents = std::string(H * W, c);
    return *this;
}

template <int H, int W>
Screen<H, W> &Screen<H, W>::move(int r, int c)
{
    int row = r * W;
    cursor = row + c;
    return *this;
}

template <int H, int W>
char Screen<H, W>::get(int r, int c) const
{
    int row = r * W;
    return contents[row+c];
}

template <int H, int W>
Screen<H, W> &Screen<H, W>::set(char c)
{
    contents[cursor] = c;

    return *this;
}

template <int H, int W>
Screen<H, W> &Screen<H, W>::set(int row, int col, char c)
{
    contents[row * W + col] = c;

    return *this;
}

template <int H, int W>
std::istream &operator>>(std::istream& in, Screen<H,W>& s)
{
    std::string input;
    in >> input;
    s.contents = input.substr(0, H*W);
    return in;
}

template <int H, int W>
std::ostream &operator<<(std::ostream& out, const Screen<H, W>& s)
{
    out << s.contents;
    return out;
}   




#endif