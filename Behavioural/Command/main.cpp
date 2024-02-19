#include<bits/stdc++.h>

struct Character{
    int x;
    int y;
    std::string name;
    Character(std::string _name){
        name=_name;
    }
    void move(int _x,int _y){
        x = _x;
        y = _y;
    }
};

class Command{
    public:
    virtual ~Command(){}
    virtual void execute(Character& c)=0;
    virtual void undo(Character& c)=0;

};

class Move: public Command{
    private:
    int x;
    int y;
    public:
    void execute(Character& c){
        int randx = rand() % 4;
        int randy = rand() % 4;
        c.move(randx,randy);
        x=randx;
        y=randy;
        std::cout<<c.name<<" moved "<<x<<", "<<y<<"\n";
    }
    void undo(Character& c){
        c.move(-x,-y);
        std::cout<<c.name<<" undo "<<-x<<" , "<<-y<<"\n";
    }
};

int main()
{
    Character Kratos("Kratos");
    std::vector<Command*>command_queue;

    Move* m1 = new Move;
    command_queue.push_back(m1);
    Move* m2 = new Move;
    command_queue.push_back(m2);
    Move* m3 = new Move;
    command_queue.push_back(m3);
    Move* m4 = new Move;
    command_queue.push_back(m4);


   for(int i=0;i<command_queue.size();i++)
   {
        command_queue[i]->execute(Kratos);
   }
   for(int i=command_queue.size()-1;i>=0;i--)
   {
    command_queue[i]->undo(Kratos);
   }

    return 0;
}