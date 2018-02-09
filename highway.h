#include <iostream>
#include <list>
#include <vector>
#include <queue>
#include <iterator>
#include "vehicle.h"
#include "constants.h"

using namespace std;

class Highway
{
    private:
        class Segment
        {
            private:
                class Entrance
                {
                    private:
                        class Toll
                        {
                            private:
                                bool IsAutomated;
                                unsigned int K;
                                unsigned int exit_from_tolls;
                            public:
                                queue<Vehicle*> VehicleQueue;
                                Toll(bool, unsigned int Enter_Node, unsigned int starting_K);
                                ~Toll();
                                unsigned int NoOfVehiclesInQueue() const { return VehicleQueue.size();  };
                                void AddVehiclesToQueue(int Enter_Node);
                                Vehicle* RemoveVehicleFromQueue(); 
                                void change_K();
                        };
                        vector<Toll*> Tolls;
                        vector<Toll*>::iterator it;        
                        unsigned int Node;
                        unsigned int RegularTolls;
                        unsigned int AutomatedTolls;
                    public:
                        Entrance(unsigned int N);
                        ~Entrance();
                        vector<Vehicle*> operate(unsigned int passing_vehicles);  
                        unsigned int NoOfRegularTolls() const { return RegularTolls; };
                        unsigned int NoOfAutomatedTolls() const { return AutomatedTolls; };
                        unsigned int VehiclesWaitingInTolls() const;
                };
                Entrance Entry;
                unsigned int Capacity;
                unsigned int Seg;
                unsigned int NoOfVehicles;
                vector<Vehicle*> Vehicles;
                vector<Vehicle*>::iterator it;
            public:
                Segment(unsigned int C, unsigned int S);
                ~Segment();
                unsigned int get_no_of_vehicles() const { return NoOfVehicles; };
                unsigned int get_capacity() const { return Capacity; };
                unsigned int enter(vector<Vehicle*> vec_lastseg);
                void operate(Segment * previous);
                vector<Vehicle*> pass(Segment*);
                void exit();
        };
        list<Segment*> segs;
    public:
        static unsigned int NSegs;
        static double Percent;
        static unsigned int max_K;
        Highway();
        ~Highway();
        void add_seg(unsigned int, unsigned int);
        unsigned int get_num_of_vehicles();
        void operate();
};