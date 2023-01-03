#ifndef VECTOR_HPP
#define VECTOR_HPP

struct Vector
{
    float x;
    float y;

    Vector(float x = 0, float y = 0) : x(x), y(y)
    {
    }

    Vector operator+(const Vector a) const
    {
        return Vector(x + a.x, y + a.y);
    }
    
    Vector operator-(const Vector a) const
    {
        return Vector(x - a.x, y - a.y);
    }

    Vector operator*(const float a) const
    {
        return Vector(x * a, y * a);
    }
};

#endif // VECTOR_HPP