Meli Omadas:
	Ioannis Charamis(1115201400220)
	Dimitra Mavroforaki(1115201400104)

Compile with:
	
Run with:
	./main 5 5 1 0.8
	segments' capacity=50

Sxediastikes epiloges:
	Oles oi domes dedomenwn pou xrisimopoioume periexoun deiktes se objects wste na periorisoume oso to dynaton ginetai tin klisi tou copy constructor
	
	1)list <Segment *> segs ->epitygxanetai eukoloteri prosvasi sto proigoumeno kai sto epomeno segment (to provlima tairiaze me ti logiki tis diplis
	syndendemenis listas)
	
	2)vector < Vehicles *> Vehicles -> ayksomeiwnetai o arithmos twn oximatwn pou yparxoun se kathe segment 
	
	3)vector <Toll *> Tolls -> endykneitai kai i domi Array (wstoso yparxei mono sti c++11) kai gi auto epileksame vector gia na xrisimopoihsoume apokleistika typous tis
				   stl pou prosferei efkolia sto debugging
	
	4)queue<Vehicle*> VehicleQueue -> taytizetai me tin logiki tis oura twn diodiwn se enan kanoniko autokinitodromo
	
Paradoxes:
	1)Kathe komvos periexei toulaxiston 1 diodio
	2)Otan ena oxima metavainei apo to ena tmima sto epomeno i katastasi etoimotitas tou allazei se not_ready. To gegonos oti itan ready na perasei sto epomeno tmima ston
	enan kyklo, den simainei oti tha einai ready na perasei sto epomeno tmima kai ston epomeno kyklo.
	3)Den paratiroume kamia kinitikotita ston prwto kyklo prosomoiwsis. Gia na symvoun oi allages(exodos apo to tmima h apo ton autokinitodromo) apaiteitai metavasi apo
	not_ready -> ready, kati pou ginetai aisthito ston deytero kyklo. (vasi tis ekfwnisis oi allages efarmozontai ston epomeno kyklo).

Sximatiki apeikonisi enos autokinitodromou me 2 segments:

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
(Ta onomata me ton asterisko den einai objects.To node einai int-identifier. H eksodos ekfrazetai me tin afairesi oximatwn.)

Paratiriseis prosomoiwsis:
	1)Gia megala capacities (>50) o autokinitodromos adeiazei
	2)Gia mikra capacities (<5) yparxei mpotiliarisma (den yparxei xwritikotita katallili wste ta autokinita na metavoun sto tmima pou vrisketai o komvos eksodou tous)

		
