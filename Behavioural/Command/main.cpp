#include<bits/stdc++.h>

// Define a Character structure with x, y coordinates and a name
struct Character {
    int x;
    int y;
    std::string name;

    // Constructor to initialize the character with a name
    Character(std::string _name) : name(_name) {}

    // Function to move the character to a new position
    void move(int _x, int _y) {
        x = _x;
        y = _y;
    }
};

// Base class representing a command
class Command {
public:
    virtual ~Command() {}

    // Abstract functions for executing and undoing a command
    virtual void execute(Character& c) = 0;
    virtual void undo(Character& c) = 0;
};

// Derived class representing a move command
class Move : public Command {
private:
    int x;
    int y;

public:
    // Function to execute a move command
    void execute(Character& c) override {
        int randx = rand() % 4;
        int randy = rand() % 4;
        c.move(randx, randy);
        x = randx;
        y = randy;
        std::cout << c.name << " moved " << x << ", " << y << "\n";
    }

    // Function to undo a move command
    void undo(Character& c) override {
        c.move(-x, -y);
        std::cout << c.name << " undo " << -x << " , " << -y << "\n";
    }
};

int main() {
    // Create a Character named Kratos
    Character Kratos("Kratos");

    // Create a vector to store pointers to Command objects
    std::vector<Command*> command_queue;

    // Create Move objects and add them to the command queue
    Move* m1 = new Move;
    command_queue.push_back(m1);

    Move* m2 = new Move;
    command_queue.push_back(m2);

    Move* m3 = new Move;
    command_queue.push_back(m3);

    Move* m4 = new Move;
    command_queue.push_back(m4);

    // Execute each command in the command queue
    for (int i = 0; i < command_queue.size(); i++) {
        command_queue[i]->execute(Kratos);
    }

    // Undo each command in reverse order
    for (int i = command_queue.size() - 1; i >= 0; i--) {
        command_queue[i]->undo(Kratos);
    }

    // Cleanup: delete dynamically allocated Move objects
    for (Command* cmd : command_queue) {
        delete cmd;
    }

    return 0;
}
