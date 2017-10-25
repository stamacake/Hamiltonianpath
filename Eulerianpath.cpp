//============================================================================
// Name : lab1.disk.cpp
// Author : stamacake
// Version :
// Copyright : stamacake corp.
// Description : Eulerian path
//============================================================================

#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	setlocale(0,"");
	map<int, vector<int> > A1; //���� - ������ ������, �������� - ������ ������ �� ������� �����
							   //������� � ����
	map<int, vector<int> > A2;
	cout<<"������� ���-�� ������:";
	int v1 = 0;
	cin>>v1;
	for (int i = 1; i <= v1; i++) {
		A2[i].push_back(0);
		cout << "���-�� ������ ������ � ������� �" << i << " : ";
		int v2 = 0;
		cin >> v2;
		for (int j = 1; j <= v2; j++) {
			cout << "������� ����� " << j << "-� ������� :";
			int v3 = 0;
			cin >> v3;
			A1[i].push_back(v3);
		
		}
	}
	for (int i = 1; i <= v1; i++) {
		int S = A1[i].size();
		cout << "������� �" << i << "\n";
		cout << "�������, ������� � ���: ";

		for (int j = 0; j<S; j++) {

			cout << A1[i][j];
			if (S - j>1) {
				cout << ",";
			}
			else {
				cout << ".";
			}
		}
		cout << "\n";

	}

	

	for (int i = 1; i <= v1; i++) {
		int S = A2[i].size();
		cout << "������� �" << i << "\n";
		cout << "�������, ������� � ���: ";

		for (int j = 0; j<S; j++) {

			cout << A2[i][j];
			if (S - j>1) {
				cout << ",";
			}
			else {
				cout << ".";
			}
		}
		cout << "\n";

	}


		vector<int> A3;

		int SizeTop = 1;
		int i1 = 0; // current top
		int i2 = 0; // last top
		A3.push_back(A1[v1][0]);
		cout << "A3 last element	" << A3[0] << endl;
		while (A3.size() != v1) {
			int exit = -55;
			cout << "���� �3  :";
			for (auto aa : A3) {
				cout << aa <<" ";
			} cout << endl;
		
		


			int lastelement = A3[A3.size() - 1];
			cout <<"last element: "<< lastelement << endl;
			SizeTop = A1[lastelement].size(); // ������ ������� �������
			cout << "size of top: " << SizeTop << endl;
			while (exit != -5) {
				
				if ((find(A2[lastelement].begin(), A2[lastelement].end(), A1[lastelement][i1]) == A2[lastelement].end())&&(find(A3.begin(), A3.end(), A1[lastelement][i1]) == A3.end())) //�������� �� ����������� ��������
				{
					
					A2[lastelement].push_back(A1[lastelement][i1]);
					
					A3.push_back(A1[lastelement][i1]);
				
					i2 = i1;
					i1 = 0;
					exit = -5;
				}
				else if (i1<SizeTop-1) {
					i1++;
					i2 = i1;
				
				}
				else {
					A3.pop_back();
					i1 = i2;

				
					A2[lastelement].clear();
				
					exit = -5;

				}

			}
		}



		for (int i = A3.size()-1; i >=0 ;i--) {
			cout << A3[i] << " ";
		}
	
	system("pause");
	return 0;
}