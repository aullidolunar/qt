#ifndef _MYTRANSLATORCLASS_H
#define _MYTRANSLATORCLASS_H

#include <QApplication>
#include <QTranslator>
#include <QLibraryInfo>

class MyTranslatorClass {
private:
	QTranslator *m_qtTranslator;
	QTranslator *m_Translator;
	QString m_qtPath;
	QString m_qmPath;
public:
	MyTranslatorClass(QApplication*, const QString&);
	void changeLanguage(const QString&);
	QString language();
	virtual ~MyTranslatorClass();
};


#endif
