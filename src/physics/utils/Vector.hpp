#pragma once
#include<array>
/* template<typename T> requires std::integral<T> */

class Vector {
    public:
        using Coordinate_t = double;
    public:
        Coordinate_t x;
        Coordinate_t y;
        Coordinate_t z;
    public:


        // Constructors
        Vector() {}
        Vector(Coordinate_t x, Coordinate_t y, Coordinate_t z) : x(x), y(y), z(z) {};

        template<typename T> requires std::integral<T>
        explicit Vector(std::array<T,3> arr) {Vector(arr[0],arr[1],arr[2]);}

        template<typename T> requires std::integral<T>
        explicit Vector(T arr[3]) {Vector(arr[0],arr[1],arr[2]);}

        ~Vector() {} 

        // Operator Overload
        Vector operator+ (const Vector& pos) const {
            return Vector(x+pos.x,y+pos.y,z+pos.z);
        }

        Vector operator- (const Vector& pos) const {
            return Vector(x-pos.x,y-pos.y,z-pos.z);
        }

        Vector operator- () const {
            return Vector(-x,-y,-z);
        }

        Coordinate_t operator * (const Vector& pos) const {
            return x*pos.x + y*pos.y + z*pos.z;
        }

        /**
         * @brief Comparaison overload. Since using c++20, we don't have to define operator != 
         * @param pos (const Vector&) 
         * @return (bool) Boolean true if all coordinates are the same. If one or multiple coordinates are differents, return false. 
         */
        bool operator == (const Vector& pos) const {
            return x==pos.x && y==pos.y && z==pos.z;
        }
        
        template<typename T>
        Vector operator *(const T& v) {
            Vector(x*v,y*v,z*v);
        }   

        /**
         * @brief Operator compare used by the std::map object. Not a real compare operator 
         * @param pos Another Vector
         * @return Boolean
         */
        bool operator < (const Vector & pos) const {
            if (x >= pos.x)
            {
                if (y >= pos.y)
                {
                    if (z >= pos.z) {
                        return false;
                    }
                }
                
            }
            return true;
        }

};

