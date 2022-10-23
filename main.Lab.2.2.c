#include <stdio.h>
#include <stdlib.h>
#include <math.h>

     double num_comput_integral_l_re(double left_boundary_a, double right_boundary_b, unsigned int intervals);
     double num_comput_integral_r_re(double left_boundary_a, double right_boundary_b,  unsigned int intervals);
     double num_comut_integral_trapecia(double left_boundary_a, double right_boundary_b,  unsigned int intervals);
     double num_comput_integral_Simps (double left_boundary_a, double right_boundary_b, unsigned int intervals);
     double integrand_expression( double x );


double max_pohibka = 0.00001;

int main()
{
     double left_boundary_a=0, right_boundary_b=1;
     double measurement_error=0, i1=0, i2=0;
     int intervals, var, i;
     double integral_s=0;

  while (1)
  {
    printf("\n\tThe left boundary a = %.2lf",left_boundary_a );
    scanf("%lf", &left_boundary_a);
    printf("\n\tThe right boundary b = %.2lf\n",right_boundary_b );
    scanf("%lf", &right_boundary_b);

    do
    {
      printf("\tEnter the number of partition intervals (N>0)\nN=");
      scanf("%u", &intervals);
    }
    while (intervals <= 0);

    printf("\n\tEnter the measurment error of integration\n  Measurment error=");
    scanf("%lf", &measurement_error);

    do
    {
      printf("\nChoose the method of calculating:\n");
      printf("\t1. By Left Rectangles:\n");
      printf("\t2. By Right Rectangles:\n");
      printf("\t3. By Trapecia:\n");
      printf("\t4. By Simps(parabola method):\n");
      scanf("%u", &var);

    if (var != 1 && var != 2 && var != 3 && var != 4)
        printf("\nYou are mistaken\n");
    }

     while (var != 1 && var != 2 && var != 3 && var != 4);
    system("cls");

    switch (var)
    {
    case 1:
    {
      int Npohib = pohibka(left_boundary_a, right_boundary_b, var);
      double i1 = num_comput_integral_l_re(left_boundary_a, right_boundary_b, Npohib);
      integral_s = num_comput_integral_l_re(left_boundary_a, right_boundary_b, intervals);
      printf("\n\n\t*Left Rectangles method*\n");
      printf("\n\ta = %.2lf \n\tb = %.2lf \n\tIntegral = %.8lf \n\tN = %d \n\ti1 = %.8lf \n\tNpohib = %d",left_boundary_a, right_boundary_b, integral_s, intervals, i1, Npohib);
    }
    break;
    case 2:
    {
      int Npohib = pohibka(left_boundary_a, right_boundary_b, var);
      double i1 = num_comput_integral_r_re(left_boundary_a, right_boundary_b, Npohib);
      integral_s = num_comput_integral_r_re(left_boundary_a, right_boundary_b, intervals);
      printf("\n\n\t======*Right Rectangles method*======\n");
      printf("\n\ta = %.2lf \n\tb = %.2lf \n\tIntegral = %.8lf \n\tN = %d \n\ti1 = %.8lf \n\tNpohib = %d", left_boundary_a, right_boundary_b , integral_s, intervals, i1, Npohib);
    }
    break;
    case 3:
    {
      int Npohib = pohibka(left_boundary_a, right_boundary_b, var);
      double i1 = num_comut_integral_trapecia(left_boundary_a, right_boundary_b, Npohib);
      integral_s = num_comut_integral_trapecia(left_boundary_a, right_boundary_b, intervals);
      printf("\n\n\t======*trapecia method *======\n");
      printf("\n\ta = %.2lf \n\tb = %.2lf \n\tIntegral = %.8lf \n\tN = %d \n\ti1 = %.8lf \n\tNpohib = %d", left_boundary_a, right_boundary_b, integral_s, intervals, i1, Npohib);
    }
    break;
    case 4:
    {
      int Npohib = pohibka(left_boundary_a, right_boundary_b, var);
      double i1 = num_comput_integral_Simps(left_boundary_a, right_boundary_b, Npohib);
      integral_s = num_comput_integral_Simps(left_boundary_a, right_boundary_b, intervals);
      printf("\n\n\t======*simps's method *======\n");
      printf("\n\ta = %.2lf \n\tb = %.2lf \n\tIntegral = %.8lf \n\tN = %d \n\ti1 = %.8lf \n\tNpohib = %d", left_boundary_a, right_boundary_b, integral_s, intervals, i1, Npohib);
    }
    break;
    }
  }
  return 0;
}


double num_comput_integral_l_re(double left_boundary_a, double right_boundary_b, unsigned int intervals)
{
  double integral_s = 0, x = 0, h;
  unsigned int i;
  h = (right_boundary_b - left_boundary_a) / intervals;
  x = left_boundary_a;
  for (i = 0; i <= (intervals - 1); i++)
  {
    integral_s += integrand_expression(x);
    x += h;
  }
  return integral_s * h;
}
double num_comput_integral_r_re(double left_boundary_a, double right_boundary_b, unsigned int intervals)
{
  double integral_s = 0, x = 0, h;
  unsigned int i;
  h = (right_boundary_b - left_boundary_a) / intervals;
  x = left_boundary_a + h;
  for (i = 0; i <= intervals; i++)
  {
    integral_s += integrand_expression(x);
    x += h;
  }
  return integral_s * h;
}
double num_comut_integral_trapecia(double left_boundary_a, double right_boundary_b, unsigned int intervals)
{
  double integral_s = 0, x = 0, h;
  unsigned int i;
  h = (right_boundary_b - left_boundary_a) / intervals;
  x = left_boundary_a + h;
  for (i = 0; i <= (intervals - 1); i++)
  {
    integral_s += (integrand_expression(x) + integrand_expression(x + h)) / 2;
    x += h;
  }
  return integral_s * h;
}
double num_comput_integral_Simps(double left_boundary_a, double right_boundary_b, unsigned int intervals)
{
  double integral_s = 0, sum1 = 0, sum2 = 0, h = 0;

  h = (right_boundary_b - left_boundary_a) / intervals;

  for (int i = 1; i <= (intervals - 1); i++)
  {
    if (i % 2 != 0)
      sum1 += integrand_expression(left_boundary_a + h * i);
    else
      sum2 += integrand_expression(left_boundary_a+ h * i);
  }
  return (integrand_expression(left_boundary_a) + integrand_expression(right_boundary_b) + 4 * sum1 + 2 * sum2) * h / 3;
}
double integrand_expression(double x)
{
  return x * pow(sin(x), 2);
}
int pohibka(double left_boundary_a, double right_boundary_b, int var)
{
  switch (var)
  {
  case 1:
  {
    int Npohib = 0, i1, i2;
    do
    {
      Npohib += 2;
      i1 = num_comput_integral_l_re(left_boundary_a, right_boundary_b, Npohib);
      i2 = num_comput_integral_l_re(left_boundary_a,right_boundary_b, Npohib + 2);
    } while (fabs(i2 - i1) > max_pohibka);
    return Npohib;
  }
  break;
  case 2:
  {
    int Npohib = 0, i1, i2;
    do
    {
      Npohib += 2;
      i1 = num_comput_integral_r_re(left_boundary_a, right_boundary_b, Npohib);
      i2 = num_comput_integral_r_re(left_boundary_a, right_boundary_b, Npohib + 2);
    } while (fabs(i2 - i1) > max_pohibka);
    return Npohib;
  }
  break;
  case 3:
  {
    int Npohib = 0, i1, i2;
    do
    {
      Npohib += 2;
      i1 = num_comut_integral_trapecia(left_boundary_a, right_boundary_b, Npohib);
      i2 = num_comut_integral_trapecia(left_boundary_a, right_boundary_b, Npohib + 2);
    } while (fabs(i2 - i1) > max_pohibka);
    return Npohib;
  }
  break;
  case 4:
  {
    int Npohib = 0, i1, i2;
    do
    {
      Npohib += 2;
      i1 = num_comput_integral_Simps(left_boundary_a, right_boundary_b, Npohib);
      i2 = num_comput_integral_Simps(left_boundary_a, right_boundary_b, Npohib + 2);
    } while (fabs(i2 - i1) > max_pohibka);
    return Npohib;
  }
  break;
  }
}
