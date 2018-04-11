#ifndef _STPW1_
#define _STPW1_

#include <time.h>

using namespace std;

class StopWatch{
	public:
			/*
			Narrative: Constructs the stop watch... although this is basically a static class...
					   I do plan on reusing this for further testing
			Pre: N/A
			Post: A constructed StopWatch with NULL values
			*/
			StopWatch(){};
			
			/*
			Narrative: Starts the stop watch
			Pre: A constructed stop watch must exist
			Post: A capture of the time when this method is called is stored
			*/
			void Start(){clock_gettime(CLOCK_REALTIME, &start);};
			
			/*
			Narrative: Gets a split of the time from the starting time
			Pre: A constructed watch must exits and the time must be started
			Post a double is returned with the difference of time
			*/
			long Split(){
				timespec split;
				clock_gettime(CLOCK_REALTIME, &split);
				return split.tv_nsec - start.tv_nsec;
			};
	
	private:
			//Data members
			timespec start;
};

#endif
