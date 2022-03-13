#include <iostream>
#include <cstdlib> //for dynamic memory allocation

using namespace std;

//CAN DUYAR 171044075

class Polynomial{ //Polynomial class
 public:
  Polynomial(); // default constructor
  Polynomial(int degree); // constructor with parameter
  Polynomial(const Polynomial& source); //copy constructor // 
  ~Polynomial(); //destructor                             //  COPY CONSTRUCTOR+DESTRUCTOR+ASSIGNMENT OPERATOR = BIG THREE 
  //Assignment operator                                   //
  Polynomial& operator=(const Polynomial& assign);
  // + OPERATOR OVERLOADING 
  friend const Polynomial operator+(const Polynomial& p1, const Polynomial& p2); // polynomial + polynomial
  friend const Polynomial operator+(const double constant, const Polynomial& p); // constant + polynomial
  friend const Polynomial operator+(const Polynomial& p,  const double constant); // polynomial + constant
  // - OPERATOR OVERLOADING
  friend const Polynomial operator-(const Polynomial& p1, const Polynomial& p2); // polnomial - polynomial
  friend const Polynomial operator-(const double constant, const Polynomial& p2); // constant - polynomial
  friend const Polynomial operator-(const Polynomial& p1, const double constant); // polynomial - constant 
  // * OPERATOR OVERLOADING 
  friend const Polynomial operator*(const Polynomial& p1, const Polynomial& p2); // polynomial * polynomial 
  friend const Polynomial operator*(const Polynomial& p1, const double constant); //polynomial * constant
  friend const Polynomial operator*(const double constant, const Polynomial& p2);  // constant * polynomial 
  
  friend ostream& operator<<(ostream& out, const Polynomial& pol); // << operator overloading
  void setCoefficient(const double co,const int index); //co means coeficient
  void setNum(const int num);
  int getNum()const;
  double getCoefficient(const int index)const;
  void show()const;
 private:
  int numb; // to keep total number of coefficients
  double* coefficients; //to keep coefficients
};

ostream& operator<<(ostream& out, const Polynomial& pol) { // insertion operator overloading
  pol.show();
  return out;
}

void Polynomial::show()const{
  bool isZero = true;
  int control = 0;
  int keep;
  for (int i = 0; i < numb; i++) {
    if (coefficients[numb - i - 1] != 0) {
      isZero = false;
      keep = control;
      cout << coefficients[numb - i - 1];
      if ((numb - i - 1) != 0)  {
        cout << "x^" << numb - i - 1 ;
      }
    }
    if (!isZero && (i < (numb - 1))) {
      control++;
      if(control-keep <= 1 && coefficients[numb - i - 2] >= 0)
        cout << " + ";
      else if(coefficients[numb - i - 2] < 0)
        cout << " ";

    }
  }
  if (isZero) {
    cout << "0";
  }
}

Polynomial::Polynomial(){
  numb = 1;
  coefficients = new double[numb];
  coefficients[0] = 0;
}


Polynomial::Polynomial(int degree){
  numb = degree + 1;
  coefficients = new double[numb];
  
  cout << "Please enter coefficients of your  "<< degree <<". degree polynomnial" << endl;
  
  for (int t = 0; t < numb; ++t) {
    cin >> coefficients[numb-t-1];
  }

}

Polynomial::Polynomial(const Polynomial& copy) { //copy constructor
  if (numb != copy.numb) {
    delete [] coefficients;
    numb = copy.numb;
    coefficients = new double[numb];
  }
  for (int i = 0; i < numb; i++) {
    coefficients[i] = copy.coefficients[i];
  }
}
    
Polynomial::~Polynomial() { //destructor
  delete [] coefficients;
}

Polynomial& Polynomial::operator=(const Polynomial& assign){ //assignment operator overloading
  if (numb != assign.numb) {
    delete [] coefficients;
    numb = assign.numb;
    coefficients = new double[numb];
  }
  for (int t = 0; t < numb; t++) {
    coefficients[t] = assign.coefficients[t];
  }
  return *this;
}

const Polynomial operator+(const Polynomial& p1, const Polynomial& p2) {
  Polynomial sum;
  if (p1.numb >= p2.numb) {
    sum.numb = p1.numb;
  } else {
    sum.numb = p2.numb;
  }
  delete [] sum.coefficients;
  sum.coefficients = new double[sum.numb];
  for (int i = 0; i < sum.numb; i++) {
    sum.coefficients[i] = 0;
    if (i < p1.numb) {
      sum.coefficients[i] += p1.coefficients[i];
    }
    if (i < p2.numb) {
      sum.coefficients[i] += p2.coefficients[i];
    }
  }
  return sum;
}

const Polynomial operator+(const Polynomial& p1, double constant) {
  Polynomial sum;
  
  sum.numb = p1.numb;
  
  delete [] sum.coefficients;
  sum.coefficients = new double[sum.numb];
  for (int i = 0; i < sum.numb; i++) {
    sum.coefficients[i] = 0;
    if (i < p1.numb) {
      sum.coefficients[i] += p1.coefficients[i];
    }
    if (i == 0) {
      sum.coefficients[i] += constant;
    }
  }
  return sum;
}


const Polynomial operator+(double constant, const Polynomial& p1) {
  Polynomial sum;
  
  sum.numb = p1.numb;
  
  delete [] sum.coefficients;
  sum.coefficients = new double[sum.numb];
  for (int i = 0; i < sum.numb; i++) {
    sum.coefficients[i] = 0;
    if (i < p1.numb) {
      sum.coefficients[i] += p1.coefficients[i];
    }
    if (i == 0) {
      sum.coefficients[i] += constant;
    }
  }
  return sum;
}



const Polynomial operator-(const Polynomial& p1, const Polynomial& p2) {
  Polynomial differ;
  if (p1.numb >= p2.numb) {
    differ.numb = p1.numb;
  } else {
    differ.numb = p2.numb;
  }
  delete [] differ.coefficients;
  differ.coefficients = new double[differ.numb];
  for (int i = 0; i < differ.numb; i++) {
    differ.coefficients[i] = 0;
    if (i < p1.numb) {
      differ.coefficients[i] += p1.coefficients[i];
    }
    if (i < p2.numb) {
      differ.coefficients[i] -= p2.coefficients[i];
    }
  }
  return differ;
}



const Polynomial operator-(const Polynomial& p1, const double constant){
  Polynomial differ;
  differ.numb = p1.numb;
  
  delete [] differ.coefficients;
  differ.coefficients = new double[differ.numb];
  for (int i = 0; i < differ.numb; i++) {
    differ.coefficients[i] = 0;
    if (i < p1.numb) {
      differ.coefficients[i] += p1.coefficients[i];
    }
    if (i == 0) {
      differ.coefficients[i] -= constant;
    }
  }
  return differ;

}


const Polynomial operator-(const double constant,const Polynomial& p1) {
  Polynomial differ;
  differ.numb = p1.numb;
  
  delete [] differ.coefficients;
  differ.coefficients = new double[differ.numb];
  for (int i = 0; i < differ.numb; i++) {
    differ.coefficients[i] = 0;
    if (i < p1.numb) {
      differ.coefficients[i] -= p1.coefficients[i];
    }
    if (i == 0) {
      differ.coefficients[i] += constant;
    }
  }



  return differ;
}




const Polynomial operator*(const Polynomial& p1, const Polynomial&p2) {
  Polynomial mul;
  mul.numb = p1.numb + p2.numb;
  delete [] mul.coefficients;
  mul.coefficients = new double[mul.numb];
  for (int i = 0; i < mul.numb; i++) {
    mul.coefficients[i] = 0;
  }
  for (int i = 0; i < p1.numb; i++) {
    for (int j = 0; j < p2.numb; j++) {
      mul.coefficients[i + j] += p1.coefficients[i] * p2.coefficients[j];
    }
  }
  return mul;
}



const Polynomial operator*(const Polynomial& p1, const double constant) {
  Polynomial mul;
  mul.numb = p1.numb;
  delete [] mul.coefficients;
  mul.coefficients = new double[mul.numb];
  for (int i = 0; i < mul.numb; i++) {
    mul.coefficients[i] = 0;
  }

  for (int i = 0; i < p1.numb; i++) {
      mul.coefficients[i] += p1.coefficients[i] * constant;
  }
  return mul;
}


const Polynomial operator*(const double constant,const Polynomial& p1) {
  Polynomial mul;
  mul.numb = p1.numb;
  delete [] mul.coefficients;
  mul.coefficients = new double[mul.numb];
  for (int i = 0; i < mul.numb; i++) {
    mul.coefficients[i] = 0;
  }

  for (int i = 0; i < p1.numb; i++) {
      mul.coefficients[i] += p1.coefficients[i] * constant;
  }
  return mul;
}
      


void Polynomial::setCoefficient(const double co, const int index) {
  if (index >= numb) {
    cerr << "\nThis polynomnial doesn't have a coefficient with this index!!!";
    exit(0);
  }
  else{
    coefficients[index] = co;
  }
}

void Polynomial::setNum(const int num){
  numb = num;
}

int Polynomial::getNum()const{
  return numb;
}

double Polynomial::getCoefficient(const int index)const{
  if (index >= numb) {
    cerr << "This polynomnial doesn't have a coefficient with this index!!!";
    exit(0);
  }
   else{
    return coefficients[index];
  }
}

/* TEST */

int main() {
  Polynomial poli1; //it equals just 0 because of default constructor
  Polynomial poli2(1); // 1, degree polynomial
  Polynomial poli3(2); // 2. degree polynomial
  Polynomial poli4(3); // 3. degree polynomial

  cout << "Polynomial1: " << poli1 << endl;
  cout << "Polynomial2: " << poli2 << endl;
  cout << "Polynomial3: " << poli3 << endl;
  cout << "Polynomial4: " << poli4 << endl;
  cout << "------------------------------" << endl;
    /* ADDITION */
  cout << "*******ADDITION***********" << endl;
  cout << "Polynomial2 + Polynomial3 \n" << (poli2 + poli3) << endl; // polynomial + polynomial 
  cout << "Polynomial4 + 7\n" << (poli4 + 7) << endl; //polynomial + constant
  cout << "10 + Polynomial1\n" << (10 + poli1) << endl; //constant + polynomial
  
  /*SUBSTRACTION*/
  cout << "*******SUBSTRACTION***********" << endl; 
  cout << "Polynomial1 - Polynomial3\n" << (poli1 - poli3) << endl; //polynomial - polynomial
  cout << "Polynomial4 - 3\n" << (poli4 - 3) << endl; //polynomial - constant
  cout << "5 - Polynomial2\n" << (5 - poli2)<< endl; // constant - polynomial

  /*MULTIPLICATION*/
  cout << "*******MULTIPLICATION**********" << endl; 
  cout << "Polnomial1 * Polynomial3: " << (poli1 * poli3) << endl; // polynomial * polynomial
  cout << "Polynomial2 * 8: " << (poli2 * 8) << endl; // polynomial * constant
  cout << "2 * Polynomial4: " << (2* poli4) << endl; // constant * polynomial 
  return 0;
}
