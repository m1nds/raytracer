#ifndef INTERVAL_HPP
#define INTERVAL_HPP

class Interval {
    public:
        Interval();
        Interval(double min, double max);

        double min();
        double max();

        double size() const;
        bool contains(double x) const;
        bool surrounds(double x) const;

        static const Interval empty, universe;

    private:
        double _min, _max;
};

#endif
