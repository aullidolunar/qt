#ifndef _MYTRANSLATOR_H
#define _MYTRANSLATOR_H

#include <QApplication>
#include <QTranslator>
#include <QLibraryInfo>

class MyTranslator {
private:
	QTranslator *m_qtTranslator;
	QTranslator *m_Translator;
	QString m_qtPath;
	QString m_qmPath;
public:
	MyTranslator(QApplication*);
	void changeLanguage(const QString&);
	const QString language();
	~MyTranslator();
};


#endif
