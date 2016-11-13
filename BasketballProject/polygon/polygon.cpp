#include "polygon.h"

polygon::polygon()
{
    napr = true;
}


void polygon::changeNormal()
{
    napr = !napr;
}


point polygon::normal() const
{
    if (!operations::isPolygon(*this))
    {
        errPolygon::errorNormal();
    }
    point p = operations::normal((*this)[0], (*this)[1], (*this)[2]);
    if (!napr)
        p = -p;
    return p;
}

plane polygon::get_plane()
{
    if (!operations::isPolygon(*this))
    {
        errPolygon::errorNormal();
    }
    plane p((*this)[0], (*this)[1], (*this)[2]);
    if (!napr)
        p.negation();
    return p;
}
