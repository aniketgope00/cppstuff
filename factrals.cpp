//mandelbrol
#include <fstream>
#include <iostream>
using namespace std;

/*
while (x*x + y*y <2*2 and iteration < max_iteration)
{
xtemp = x*x-y*y + x0
y = 2*x*y + y0
x = xtemp
iteration = iteration + 1
}
*/

int findMandelbrotN(double cr, double ci, int max_iterations)
{
    int i = 0;
    double zr = 0.0, zi = 0.0;
    while (i<max_iterations && zr*zr + zi*zi < 4.0)
    {
        double temp = zr*zr - zi*zi + cr;
        zi = 2.0 * zr * zi + ci;
        zr = temp;
        i++;
    }
    return i;

}


double mapToReal(int x, int imageWidth, double minR, double maxR)
{
    double range = maxR - minR;
    // [0, width]
    // [0, maxR - minR] - val * range / width
    // [minR,maxR] - last step + minR
    return x * (range/imageWidth) + minR;
}

double mapToImaginary(int y, int imageHeight, double minI, double maxI)
{
    double range = maxI - minI;
    return y * (range/imageHeight) + minI;
}



int main()
{
    //get the required input values from file
    ifstream fin("input.txt");
    int imageWidth, imageHeight, maxN;
    double minR, maxR, minI, maxI;
    if (!fin)
    {
        cout<<"Could not open file!"<<endl;
        cin.ignore();
        return 0;
    }
    fin>> imageWidth>>imageHeight>>maxN;
    fin>>minR>>maxR>>minI>>maxI;
    fin.close();
    //Open the output file, write the PPM header
    ofstream fout("output_image.ppm");
    fout<<"P3"<<endl;//magic number -- PPM file
    fout<<imageWidth<<" "<<imageHeight<<endl;
    fout<<"256"<<endl; //max value of a pixel RGB value

    //For every pixel:
   for(int y=0;y<imageHeight;y++)
   {
        for (int x=0;x<imageWidth;x++)
        {
            //  Find the real and imaginary value for c, corresponding to theat x,y pixel in the image
            double cr = mapToReal(x, imageWidth, minR, maxR);
            double ci = mapToImaginary(y, imageHeight, minI, maxI);
            //  Find the number of iterations in the Mandelbrot formula using said c
            int n = findMandelbrotN(cr,ci,maxN);
            //  Map the resulting number to an RGB value.
            int r = (n%256);//change for more interesting colors
            int g = (n%256);//change for more interesting colors
            int b = (n%256);//change for more interesting colors
            
            //   Output it to the image
            fout << r << " "<< g<<" "<<b<< " ";
        }
        fout<<endl;
   }
   fout.close();
   cout<< "Finished!"<<endl;
   return 0;
    
}
