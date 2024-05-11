int main()
{
int c=1;
int *cp = &c;
int &cr = c;
int &crr = cr;

cout << &c << " "<< &cp << " "<< &cr<<"\n";
cout << c << " "<< *cp << " "<<  cr<<"\n";
cout << crr << " "<< &crr << " "<< cr <<" "<<&cr<<" "<< c<<" " << &c<<"\n";

cout<<sizeof (c)<<" "<<sizeof (cp);
cout<<" "<<sizeof (cr)<<" "<<sizeof (crr)<<"\n";
cout<<" "<<sizeof (&c)<<" "<<sizeof (&cr)<<" "<<sizeof (&crr)<<"\n";

*cp = 2;
cout << &c << " "<< &cp << " "<< &cr<<"\n";
cout << c << " "<< *cp << " "<<  cr<<"\n";
cout << crr << " "<< &crr << " "<< cr <<" "<<&cr<<" "<< c<<" " << &c<<"\n";

cout<<sizeof (c)<<" "<<sizeof (cp);
cout<<" "<<sizeof (cr)<<" "<<sizeof (crr)<<"\n";
cout<<" "<<sizeof (&c)<<" "<<sizeof (&cr)<<" "<<sizeof (&crr)<<"\n";
}