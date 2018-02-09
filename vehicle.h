#include <iostream>
#include <cstdlib>

using namespace std;

class Vehicle
{
    private:
        int exit_node;
        bool is_ready;
        int route;
    public:
        Vehicle(unsigned int no_of_segs,int r=-1,int pay=-1): route(r), is_ready(false)
        {
            if (route!=-1) /*oximata pou kataskevazontai kata tin kataskevi tou tmimatos*/
            {
                exit_node=rand()%(no_of_segs + 1 - route-1) + (route + 1);
                cout << "A Vehicle has entered a part of highway" << endl;
            }
            else /*oximata pou kataskevazontai sta diodia*/
            {
                exit_node=rand()%(no_of_segs + 1 - pay-1) + (pay + 1);
                cout << "A Vehicle has entered a toll queue" << endl;
            }
        }
        ~Vehicle() { cout << "A Vehicle has been destroyed!" << endl; }
        int get_route() const { return route; }
        bool IsReady() const { return is_ready; }
        int ExitNode() const { return exit_node; }
        void ready() { is_ready = true; }
        void not_ready() { is_ready = false; }
        int move_vehicle() { return ++route; }
};