#include "TableSortedList.h"
#include "ListArray.h"
using CSC2110::ListArray;
#include "ListArrayIterator.h"
using CSC2110::ListArrayIterator;
#include "CD.h"
using CSC2110::CD;
#include "Text.h"
using CSC2110::String;

#include <iostream>
using namespace std;

void deleteCDs(ListArray<CD>* list)
{
   ListArrayIterator<CD>* iter = list->iterator();

   while(iter->hasNext())
   {
      CD* cd = iter->next();
      delete cd;
   }
   delete iter;
}

int main()
{
   ListArray<CD>* cds = CD::readCDs("cds.txt");
   int num_items = cds->size();
   cout << num_items << endl;

   //DO THIS
   //thoroughly test your table
	
	ListArrayIterator<CD>* iter = cds->iterator();
	TableSortedList<CD>* tsl=new TableSortedList<CD>(&CD::compare_items,&CD::compare_keys);
	while(iter->hasNext())
	{
		tsl->tableInsert(iter->next());
	}
	num_items=tsl->tableSize();
	cout << num_items << endl;
	ListDoublyLinkedIterator<CD>* ldli= tsl->iterator();
	while(tsl->tableIsEmpty()==false)
	{
		CD* cD=ldli->next();
		CD* cdD=tsl->tableRetrieve(cD->getKey());
		cdD->displayCD();
		tsl->tableRemove(cD->getKey());
	}
	




   deleteCDs(cds);
   delete cds;
   delete tsl;
   return 0;
}
