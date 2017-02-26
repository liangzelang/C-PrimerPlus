#include <iostream>
#include <string>
#include <vector>

struct Review {
	std::string title;
	int rating;
}; //结构体记得要加分号，搞了好多次了

bool FillReview(Review & rr);
void ShowReview(const Review & rr);

int main()
{
	using std::cout;
	using std::vector;
	vector<Review> books;
	Review temp;
	while(FillReview(temp))
		books.push_back(temp);
	int num = books.size();

	if(num > 0 )
	{
		cout << "Thank you , you entered the following : \n" << "rating\t books\n ";
		for(int i=0;i<num;i++)
		{
			ShowReview(books[i]);
		}
		cout << "Reprising: \n" << "Rating\t Books\n";
		vector<Review>::iterator pr;
		for(pr = books.begin();pr!=books.end();pr++)
		{
			ShowReview(*pr);
		}
		vector<Review> oldlist(books); //复制构造函数
		if(num > 3)
		{
			//remove 2 items
			books.erase(books.begin()+1,books.begin()+3);
			cout << "After erasure : \n";
			for(pr = books.begin();pr!= books.end();pr++)
			{
				ShowReview(*pr);
			}
			books.insert(books.begin(),oldlist.begin()+1,oldlist.begin()+2);
			cout << "After insertion: \n";
			for(pr = books.begin(); pr!=books.end(); pr++)
			{
				ShowReview(*pr);
			}
		}
		books.swap(oldlist);
		cout << "Swapping oldlist with books: \n ";
		for(pr = books.begin();pr!= books.end(); pr++)
			ShowReview(*pr);
	}
	else
		cout << "Nothing entered ,nothing gained.\n";
	system("pause");
	return 0;
}

bool FillReview(Review & rr)
{
	std::cout << "enter book title (quit to quit):";
	std::getline(std::cin,rr.title);
	if(rr.title =="quit")
	{
		return false;
	}
	std::cout << "enter book rating: ";
	std::cin >> rr.rating;
	if(!std::cin)
		return false;
	while(std::cin.get()!='\n')
		continue;
	return true;
}

void ShowReview(const Review & rr)
{
	std::cout << rr.rating << "\t" << rr.title << std::endl;
}