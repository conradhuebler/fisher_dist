/*
 * The MIT License (MIT)
 * 
 * Copyright (c) 2017 Conrad Hübler
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 * 
 * Simple but not too fast f value calculator for fisher's test
 * Precision between 1E-3 and 1E-4
 */

#ifndef fisher_dist
#define fisher_dist

#include <cmath>
#include <iostream>
#include <vector>

/*! \brief Calculates the fisher distribution for an x value between 0 and 1
 * \sa f_dist(double x, double m, double n)
 * \param x value
 * \param m Degree of Freedom
 * \param n Degree of Freedom
 * Calculates the the fisher distribution at a given point for the degrees of freedom m and n (integers)
 */
inline double f_dist(double x, double m, double n)
{
    return pow(m,m*0.5)*pow(n,n*0.5)*(tgamma(m*0.5+n*0.5))/((tgamma(m*0.5)*tgamma(n*0.5)))*(pow(x,(m*0.5-1))/pow((m*x+n),(m+n)*0.5));
}

/*! \brief Integrates the fisher distribution from zero up to x
 * 
 * \sa impsonIntegrateMethod(double lower, double upper, double m, double n)
 * \param lower lower limit for integration
 * \param upper upper limit for integration
 * \param m Degree of Freedom
 * \param n Degree of Freedom
 * Integration is done with the SimpsonMethod
 */
inline double SimpsonIntegrateMethod(double lower, double upper, double m, double n)
{
    double integ = 0;
    double x = 0;
    int iter = 0;
    double delta = 1E-4;
    int maxiter = 10000;
    x = lower;
    while(iter < maxiter)
    {
        x += delta;
        double b = x + delta;
        integ += (b-x)/6*(f_dist(x,m,n)+4*f_dist((x+b)/2,m,n)+f_dist(b,m,n));
        if(integ >= upper)
            break;
    }
    return x;
}
/*! \brief Cpp analog to the octave and excel finv
 * 
 * \sa finv (x, m, n)      
 * \param x element x
 * \param m Degree of freedom
 * \param n Degree of freedom
 *     For each element of X, compute the quantile (the inverse of the                                                                                                                         
 *     CDF) at X of the F distribution with M and N degrees of freedom.
 *     (taken form octave manual)
 */
inline double finv(double x, double m, double n)
{
    if(x > 1 || x < 0)
        throw (-1);
    std::vector<double >parameter = { m,  n };
    double f_value =   SimpsonIntegrateMethod(0, x, m, n);
    return f_value;
}

#endif