# include <iostream>
# include "timer.hpp"

void Timer::start(){
  t_start = clock::now();
  t_end = t_start;
}

void Timer::stop(){
  lap();
}

void Timer::lap(){
  clock::time_point tmp = clock::now();

  // get laptime
  duration_t laptime;
  laptime = tmp - t_end;
  
  // check if this lap was faster
  if (t_min > laptime || t_laps.size() == 0) { 
    t_min = laptime;
  }

  // save time of this lap
  t_laps.push_back(laptime);
  t_end = tmp;
}

Timer::Timer() {};

void Timer::reset(){
  t_laps = std::vector<duration_t>();
  start();
}

double Timer::duration() const {
  if (t_laps.size() > 0){
    /* returning time in seconds! thats what the divisor is for */
    auto dur = std::chrono::duration_cast<prec>(t_end - t_start);
    return double(dur.count())/divisor;
  }
  else {
    std::cerr << "Before calling Timer::duration() you need to call Timer::lap() or Timer::stop()!\n";
    return 0.;
  }
}

double Timer::mean() const {
  if (t_laps.size() > 0){
    return duration()/t_laps.size();
  }
  else {
    std::cerr << "Before calling Timer::mean() you need to call Timer::lap() or Timer::stop()!\n";
    return 0.;
  }
}

double Timer::min() const {
  auto min = std::chrono::duration_cast<prec>(t_min);
  return double(min.count())/divisor;
}

