
Compile with:
	
Run with:
	./main 5 5 1 0.8
	segments' capacity=50

Designing options: 
	Every data structure that we use contains pointer to objects. Our goal is to call the copy constructor the least possible.
	
	1)list <Segment *> segs ->easy access to previous and next segment (double linked list)
	
	2)vector < Vehicles *> Vehicles -> the number of vehicles in each segment is not the same during the simulation
	
	3)vector <Toll *> Tolls -> data structure Array is also recommended(available only in c++11). We are using vector because stl types are compatible and easy to debug
	
	4)queue<Vehicle*> VehicleQueue -> in real life cars wait in queues to pass the tolls

We have made the admissions below:
	1)Every node has at least one toll
	2)When a vehicle passes to the next segment its state becomes "not_ready". The fact that it was ready to pass to the next segment does not ensure that it will be ready the next cycle of the simulation.
	3)There is no movement during the first cycle of the simulation. Actions like exit segment or exit highway may take place during the second cycle, because vehicles state must change (not_ready->ready). Changes are also noticable during the next cycle.

Schematic representation of a highway with 2 segments:

	         (node2)*	-----|     
	       //	\\           |
	      //|	|\\          |
	     //	|	| \\         |
	   null	|	|  exit1*    |
		|seg1	|            |
		|	|            |
		 (node1)*            |
	       //	\\            >Highway
	      //|	|\\          |
	     //	|	| \\         |
    entrance1	|	|  exit0*    |
		|	|            |
		|	|            |
		|seg0	|            |
		|	|            |
		 (node0)*            |
		//      \\           |
       	       //        \\          |
      	      //          \\         |
	entrance0          null-------
(Names with asterisk (*) are not objects. Node is type int-identifier. Exit is implemented by subtracting vehicles.)

Comments:
	1)Highway empties in high capacities (>50)
	2)We have bottleneck in low capacities (<5) (Vehicles cannot be moved to the segment that host their exit node due to inappropriate capacity)

		
