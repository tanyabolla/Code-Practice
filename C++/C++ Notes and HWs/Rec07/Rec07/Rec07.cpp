#include <iostream>
#include <vector>
#include <string>
using namespace std;

class PrintedMaterial {
public:
	PrintedMaterial(unsigned numPages) : numOfPages(numPages) {}
	virtual void displayNumPages() const = 0;
protected:
private:
	unsigned numOfPages;
};

void PrintedMaterial::displayNumPages() const {
	cout << numOfPages << endl;
}

class Magazine : public PrintedMaterial {
public:
	Magazine(unsigned numPages) : PrintedMaterial(numPages) {}
	void displayNumPages() const {
		cout << "Magazine Pages: ";
		PrintedMaterial::displayNumPages();
		cout << endl;
	}
protected:
private:
};

class Book : public PrintedMaterial {
public:
	Book(unsigned numPages) : PrintedMaterial(numPages) {}
	void displayNumPages() const {
		cout << "Book Pages: ";
		PrintedMaterial::displayNumPages();
		cout << endl;
	}
protected:
private:
};

class TextBook : public Book {
public:
	TextBook(unsigned numPages, unsigned numIndxPgs) : Book(numPages), numOfIndexPages(numIndxPgs){}
	void displayNumPages() const {
		cout << "Textbook Pages: ";
		PrintedMaterial::displayNumPages();
		cout << "Index pages: " << numOfIndexPages << endl;
	}
protected:
private:
	unsigned numOfIndexPages;
};

class Novel : public Book {
public:
	Novel(unsigned numPages) : Book(numPages) {}
	void displayNumPages() const{
		cout << "Novel Pages: ";
		PrintedMaterial::displayNumPages();
		cout << endl;
	}
protected:
private:
};

// tester/modeler code
int main()
{
	TextBook t(5430, 23);
	Novel n(213);
	Magazine m(6);

	t.displayNumPages();
	n.displayNumPages();
	m.displayNumPages();

	//cout << "\nA PrintedMaterial material object!\n";
	//PrintedMaterial pm(2345);
	//pm.displayNumPages();

	//pm = t; // like putting a t into a vector of PrintedMaterials
	//pm.displayNumPages();

	/*PrintedMaterial* pmPtr;
	pmPtr = &t;
	pmPtr->displayNumPages();
	cout << "\n";*/

	// Storing generic objects in a vector 
	cout << "\n\nNow we'll use a container. Yea!!!\n\n";
	vector<PrintedMaterial*> printedMaterial;
	printedMaterial.push_back(&t);
	printedMaterial.push_back(&n);
	printedMaterial.push_back(&m);
	for (size_t i = 0; i < printedMaterial.size(); i++)
	{
		printedMaterial[i]->displayNumPages();
		cout << endl;
	}

	system("pause");
}
