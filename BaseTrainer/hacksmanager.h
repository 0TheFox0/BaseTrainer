#ifndef HACKSMANAGER_H
#define HACKSMANAGER_H

#include <QObject>
#include <Windows.h>
class HacksManager : public QObject
{
	Q_OBJECT

public:
	HacksManager(QObject *parent);
	~HacksManager();

public slots:
	bool isActive();
	void activate(bool state);

	bool Gm();
	void setGm(bool state);

	bool Vac();
	void setVac(bool state);
private:
	bool Jump(unsigned long ulAddress, void* Function, unsigned long ulNops);
	bool WriteAddress(__in LPVOID lpcvBase, __in LPCVOID lpcvWriteValue, __in size_t uSize);

	bool m_active;

	bool m_Gm;
	bool m_Vac;
};

#endif // HACKSMANAGER_H
