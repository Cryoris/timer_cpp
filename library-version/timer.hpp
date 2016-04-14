# ifndef TIMER_HPP
# define TIMER_HPP

# include <chrono>
# include <vector>

/* USAGE: Timer t;
 *        t.start(); ... thing to measure ...; t.end();
 *        double duration = t.duration();                */

class Timer{
  typedef std::chrono::nanoseconds prec;
  typedef std::chrono::high_resolution_clock clock;
  typedef std::chrono::duration<double> duration_t;
  private:
    static const unsigned divisor = 1e9;
    clock::time_point t_start, t_end;
    duration_t t_min;
    std::vector<duration_t> t_laps;

  public:

   Timer();
   void start();
   void stop();
   void lap();
   void reset();

   double duration() const;
   double mean() const;
   double min() const;

};

# endif
