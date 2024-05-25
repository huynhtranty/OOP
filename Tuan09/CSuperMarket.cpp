#include "CSuperMarket.h"

void CSuperMarket::Input() {
	while (cin.peek() != EOF ) {
		char c;
		c = cin.peek();
		switch (c)
		{
		case 'E': {
			CGoods* tmp = new CElectronic();
			tmp->Input();
			SuperMarket.push_back(tmp);
			break;
		}
		case 'T': {
			CGoods* tmp = new CTerracotta();
			tmp->Input();
			SuperMarket.push_back(tmp);
			break;
		}
		case 'F': {
			CGoods* tmp = new CFood();
			tmp->Input();
			SuperMarket.push_back(tmp);
			break;
		}
		default:
			break;
		}
		cin.ignore();
	}
}

void CSuperMarket::Output() {
	freopen("OUTPUT.TXT", "wt", stdout);
	cout << SuperMarket.size() << " Máº·t hÃ ng:" << endl;
	for (int i = 0; i < SuperMarket.size(); i++) {
		cout << i + 1 << ". ";
		SuperMarket[i]->Output(); 
		if (i < SuperMarket.size() - 1) {
			cout << endl;
		}
	}
}

void CSuperMarket::ViewExpDate() {
	// liet ke so luong ton kho con lai da het han
	freopen("EXPDATE.TXT", "wt", stdout);
	CDate expDate = getDate();
	for (int i = 0; i < SuperMarket.size(); i++) {
		if (auto food = dynamic_cast<CFood*>(SuperMarket[i])) {
			if (expDate > food->getFoodDate()) {
				food->PrintFood();
			}
			
		}
	}

}

void CSuperMarket::Delete() {
	// xoa dua vao nhap tu ban phim 
	freopen("CON", "rt", stdin);
	cin.clear();
	string code;
	cin >> code;
	code += ' ';
	for (int i = 0; i < SuperMarket.size(); i++) {
		if (code == SuperMarket[i]->getCode()) {
			SuperMarket.erase(SuperMarket.begin() + i);
		}
	}
}


void CSuperMarket::Buy() {
	// in ra hoa don voi real time
	//CDate expDate = getDate();
	// set lai so luong hang con lai
	cin.clear();
	freopen("BUY.TXT", "rt", stdin);
	string Phone;
	getline(cin, Phone, '\n');
	vector<string> codes;
	vector<string> names;
	vector<float> QuantityProduct;
	string tmpC;
	string tmpN;
	int tmpQ;
	while (cin.peek() != EOF) {
		getline(cin, tmpC, ',');
		getline(cin, tmpN, ',');
		cin >> tmpQ;
		cin.ignore();
		codes.push_back(tmpC);
		names.push_back(tmpN);
		QuantityProduct.push_back(tmpQ);
	}

	freopen("INVOICE.TXT", "wt", stdout);
	cout << Phone << endl;
	// get time
	auto now = std::chrono::system_clock::now();

	std::time_t now_time_t = std::chrono::system_clock::to_time_t(now);

	std::tm* now_tm = std::localtime(&now_time_t);

	int year = now_tm->tm_year + 1900;
	int month = now_tm->tm_mon + 1;
	int day = now_tm->tm_mday;

	const char* day_names[] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };

	std::cout << std::put_time(std::localtime(&now_time_t), "%T ")
		<< day_names[now_tm->tm_wday] << " "
		<< std::put_time(std::localtime(&now_time_t), "%d/%m/%Y") << endl; 

	// get information of bill
	vector<string> prices;
	for (int i = 0; i < codes.size(); i++) {
		string s = codes[i] + ' ';
		for (int j = 0; j < SuperMarket.size(); j++) {
			if (s == SuperMarket[j]->getCode()) {
				prices.push_back(SuperMarket[j]->getPrice());
				SuperMarket[j]->setNumOfProduct(QuantityProduct[i]);
			}
		}
	}
	string total = "0";
	string discount = "0";
	for (int i = 0; i < codes.size(); i++) {
		cout << i +1 << ". " << codes[i] << "," 
			  << names[i] << ":" << QuantityProduct[i] << " x" <<  prices[i] <<  " = " 
			  << ToTalMoney(QuantityProduct[i], prices[i]) << " VND" << endl;
		total = sumTwoString(total, ToTalMoney(QuantityProduct[i], prices[i]));
		switch (day)
		{
		case 5: {
			string s = codes[i];
			if (s[0] == 'F') {
				discount = sumTwoString(discount, ToTalMoney(0.2, prices[i]));
			}
			break;
		}
		case 2: {
			string s = codes[i];
			if (s[0] == 'E') {
				discount = sumTwoString(discount, ToTalMoney(0.15, prices[i]));
			}
			break;
		}
		case 3: {
			string s = codes[i];
			if (s[0] == 'E') {
				discount = sumTwoString(discount, ToTalMoney(0.15, prices[i]));
			}
			break;
		}
		case 0: {
			string s = codes[i];
			if (s[0] == 'T') {
				discount = sumTwoString(discount, ToTalMoney(0.3, prices[i]));
			}
			break;
		}
		case 6: {
			string s = codes[i];
			if (s[0] == 'T') {
				discount = sumTwoString(discount, ToTalMoney(0.3, prices[i]));
			}
			break;
		}
		default:
			break;
		}
	}
	if (checkTotal(total)) {
		total = ToTalMoney(0.9, total);
	}
	cout << "Giáº£m giÃ¡: "<< discount << " VND" << endl;
	cout << "Sá»‘ tiá»n thanh toÃ¡n: " << total << " VND" << endl;
}

void CSuperMarket::ViewQuantity() {
	// in ra so luong het hang khi da MUA
	freopen("QUANTITY.TXT", "wt", stdout);
	int count = 0;
	for (int i = 0; i < SuperMarket.size(); i++) {
		if (SuperMarket[i]->getNumOfProduct() == 0) {
			count++;
		}
	}
	cout << count << endl;
	int stt = 1;
	for (int i = 0; i < SuperMarket.size(); i++) {
		if (SuperMarket[i]->getNumOfProduct() == 0) {
			string code = SuperMarket[i]->getCode();
			code = code.substr(0, code.length() - 1);
			cout << stt << " " << code << ", " << SuperMarket[i]->getName() << endl;
			stt++;	
		}
	}
}