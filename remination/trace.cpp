#include <stdio.h>
class Trace{
public:
    Trace(FILE* of=stderr, bool noisy=false):_noisy(noisy),_of(of){}
    void print(const char *s){
        if(_noisy)
            fprintf(_of,"%s",s);
    }
    void on(){_noisy=true;}
    void off(){_noisy=false;}
private:
    bool _noisy;
    FILE *_of;
};

int main(){
    Trace t;
    t.print("first trace msg\n");
    t.off();
    t.print("you can't see this\n");
    t.on();
    t.print("now, you can see me\n");
    return 0;
}
