#pragma once
#ifndef _HANOI_ITEM_H
#define _HANOI_ITEM_H

class CHanoiItem {
public:
	CHanoiItem(int nNumber, char nSource, char nStation, char nTarget)
		: m_nNumber(nNumber), m_nSource(nSource), m_nStation(nStation), m_nTarget(nTarget) {}
	CHanoiItem(const CHanoiItem& hSource)
		:m_nNumber(hSource.m_nNumber), m_nSource(hSource.m_nSource), m_nStation(hSource.m_nStation), m_nTarget(hSource.m_nTarget) {}
	CHanoiItem& operator=(const CHanoiItem& hSource) {
		m_nNumber = hSource.m_nNumber;
		m_nSource = hSource.m_nSource;
		m_nStation = hSource.m_nStation;
		m_nTarget = hSource.m_nTarget;
		return *this;
	}
	virtual ~CHanoiItem() {}
	int GetNumber() { return m_nNumber; }
	char GetSource() { return m_nSource; }
	char GetStation() { return m_nStation; }
	char GetTarget() { return m_nTarget; }
	static const char A = 'A';
	static const char B = 'B';
	static const char C = 'C';
	static const char E = 'E';
private:
	int m_nNumber;
	char m_nSource = 'A';
	char m_nStation = 'B';
	char m_nTarget = 'C';

};
#endif//_HANOI_ITEM_H