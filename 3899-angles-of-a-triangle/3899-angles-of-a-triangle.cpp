class Solution {
public:
    vector<double> internalAngles(vector<int>& sides) {
        double a=sides[0];
        double b=sides[1];
        double c=sides[2];
        if(a+b>c && a+c>b && b+c>a){
            double x=acos((b*b + c*c - a*a)/(2*b*c));
            double y=acos((a*a + c*c -b*b)/(2*a*c));
            double z=acos((a*a + b*b -c*c)/(2*a*b));

            x=x*(180/M_PI);
            y=(y*180)/M_PI;
            z=(z*180)/M_PI;
            vector<double>ans= {x,y,z};
            sort(ans.begin(),ans.end());
            return ans;
        }

        return{};
    }
};