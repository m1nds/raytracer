#include <utils/interval.hpp>
#include <utils/constants.hpp>


const Interval Interval::empty    = Interval(+INF, -INF);
const Interval Interval::universe = Interval(-INF, +INF);

Interval::Interval() : _min(+INF), _max(-INF) {}

Interval::Interval(double min, double max) : _min(min), _max(max) {}

double Interval::min() {
    return this->_min;
}

double Interval::max() {
    return this->_max;
}

double Interval::size() const {
    return this->_max - this->_min;
}

bool Interval::contains(double x) const {
    return this->_min <= x && x <= this->_max;
}

bool Interval::surrounds(double x) const {
    return this->_min < x && x < this->_max;
}

double Interval::clamp(double x) const {
    if (x < this->_min) return this->_min;
    if (x > this->_max) return this->_max;
    return x;
}
