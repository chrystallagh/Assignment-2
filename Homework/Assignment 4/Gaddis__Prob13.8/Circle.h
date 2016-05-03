/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Circle.h
 * Author: chrystallahavadjia
 *
 * Created on April 28, 2016, 9:17 PM
 */

#ifndef CIRCLE_H
#define CIRCLE_H

class Circle
{
    private:
        float radius;
        float pi;
    public:
        Circle(); // default constructor 
        Circle(float); // 2nd constuctor
        void setRadius(float);
        float getRadius() const;
        float getArea() const;
        float getDmeter() const;
        float getCrcmfrence() const;
};

#endif /* CIRCLE_H */

