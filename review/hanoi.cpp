#include<iostream>
#include<stack>
#include "hanoi.h"
void Print(CHanoiItem* pItem)
{
	std::cout << "#" << pItem->GetNumber()
		<< ": from" << pItem->GetSource() << " to " << pItem->GetTarget() <<
		"\n";
}

void Hanoi(std::stack<CHanoiItem*>& hStack) {
	while (!hStack.empty()) {
		CHanoiItem* pTop = hStack.top();
		hStack.pop();
		if (pTop->GetStation() == CHanoiItem::E || pTop->GetNumber() == 1) {
			Print(pTop);
			delete pTop;
			continue;
		}

		//station : source:target
		CHanoiItem* pItem = new CHanoiItem(pTop->GetNumber() - 1, pTop->GetStation(), pTop->GetSource(), pTop->GetTarget());
		hStack.push(pItem);
		//Just one item
		pItem = new CHanoiItem(pTop->GetNumber(), pTop->GetSource(), CHanoiItem::E, pTop->GetTarget());
		hStack.push(pItem);

		// source : target : station
		pItem = new CHanoiItem(pTop->GetNumber() - 1, pTop->GetSource(), pTop->GetTarget(), pTop->GetStation());
		hStack.push(pItem);
	}
}
	
	int main()
	{
		std::stack<CHanoiItem*> hStack;
		CHanoiItem* pItem = new CHanoiItem(3, CHanoiItem::A, CHanoiItem::B, CHanoiItem::C);
		hStack.push(pItem);

		Hanoi(hStack);

		return 0 ;
	}