
#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;
void initVectors(vector<int> &, vector<int> &, vector<double> &);
void calcSales(vector<int>, vector<double>, vector<double> &);
void showOrder(vector<double>, vector<int>);
void dualSort(vector<int> &, vector<double> &);
void showTotals(vector<double>, vector<int>);

int main()
{
  vector<int> id;
  vector<int> units;
  vector<double>prices;
  vector<double>sales;

  // initialize vectors
  initVectors(id, units, prices);

  //calculate sales
  calcSales(units, prices, sales);

  dualSort(id, sales);

  cout << fixed << showpoint << setprecision(2);

  showOrder(sales, id);
  showTotals(sales, units);
  return 0;
}

void initVectors(vector<int> &id, vector<int> &units, vector<double> &prices)
{
  for(int i=914; i<=922; i++)
    id.push_back(i);

  // initialize units vector
  units.push_back(842);
  units.push_back(416);
  units.push_back(127);
  units.push_back(514);
  units.push_back(437);
  units.push_back(269);
  units.push_back(97);
  units.push_back(492);
  units.push_back(212);

  //initialize prices vector
  prices.push_back(12.95);
  prices.push_back(14.95);
  prices.push_back(18.95);
  prices.push_back(16.95);
  prices.push_back(21.95);
  prices.push_back(31.95);
  prices.push_back(14.95);
  prices.push_back(14.95);
  prices.push_back(16.95);
}
void calcSales(vector<int> units, vector<double> prices, vector<double>&sales)
{
  for(int i=0; i < units.size(); i++)
    sales.push_back(units[i] * prices[i]);
}

void dualSort(vector<int> &id, vector <double>&sales)
{

  int startScan, maxIndex, tempid, size;
  double maxValue;

  size = id.size();
  for(startScan =0; startScan <(size-1); startScan++ )
  {
      maxIndex = startScan;
      maxValue = sales[startScan];
      tempid =id[startScan];
      for(int index = startScan+1; index <size; index++)
      {
            if (sales[index] > maxValue )
        {
            maxValue = sales[index];
            tempid = id[index];
            maxIndex = index;
        }
      }
      sales[maxIndex]= sales[startScan];
      id[maxIndex]= id[startScan];
      sales[startScan] = maxValue;
      id[startScan]= tempid;

  }
}
void showOrder(std::vector<double> sales, std::vector<int> id) {
  cout << "Product Number \tSales\n";
  cout <<"----------------------------------------\n";
  for (int index =0; index < id.size(); index++ ) {
    cout << id[index] << "\t\t$";
    cout << setw(8) << sales[index] << endl;
  }
  cout << endl;
}
void showTotals(vector<double> sales, vector<int> units)
{
  int totalUnits=0;
  double totalSales=0.0;
  cout << "Product Number\tSales\n";
  cout << "------------------------------------------\n" ;
  for (int i = 0; i < units.size(); i++)
  {
    totalUnits+=units[i];
    totalSales+=sales[i];
  }
  cout << "Total Units Sold      " << totalUnits << endl;
  cout << " Total Sales:        $" << totalSales <<endl;
}
