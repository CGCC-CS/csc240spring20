#include<iostream>
#include<thread>
#include<mutex>

// compile with:
//   g++ threads.cpp --std=c++11 -pthread

std::mutex writeMutex;

// This funtion counts to 10 with a small random delay between counts
//   The tabs argument lets us differentiate between different
//   threads visually.  
void count_to_ten(int tabs) {
    int delay;

    for(int jj=0;jj<10;jj++) {
      delay = ((tabs % 4) * 100) + (std::rand() % 1000);  
      std::this_thread::sleep_for(std::chrono::milliseconds(delay));

      // The next line locks the output stream so the threads don't
      //    write over each other.  Try commenting it out to see
      //    what happens.
      std::unique_lock<std::mutex> lock(writeMutex);
      for(int ii=0;ii<tabs;ii++) {
          std::cout << "\t";
      }
      std::cout << jj << std::endl;
      // Mutex freed when scope exit
    }
}

int main() {
  int numThreads = 6;
  std::thread t[numThreads];

  srand(time(NULL));
  
  // Create the threads
  for(int ii=0;ii<numThreads;ii++) {
    t[ii] = std::thread(count_to_ten, ii);
  }

  // Wait for each thread to return
  for(int ii=0;ii<numThreads;ii++) {
    t[ii].join();
  }
 
  std::cout << "FINISHED" << std::endl;
  return 0;
}
