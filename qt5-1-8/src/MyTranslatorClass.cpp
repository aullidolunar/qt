#include "MyTranslatorClass.h"

MyTranslatorClass::MyTranslatorClass(QApplication* _app) : 
	m_qtPath(QLibraryInfo::location(QLibraryInfo::TranslationsPath)), m_qmPath(PROGRAM_QM)
{
	m_qtTranslator = new QTranslator(_app);
	m_Translator = new QTranslator(_app);
	
	QString langName = QLocale::system().name();
	
	m_qtTranslator->load("qt_" + langName, m_qtPath);
	_app->installTranslator(m_qtTranslator);
	
	m_Translator->load(langName, m_qmPath);
	_app->installTranslator(m_Translator);
}

void MyTranslatorClass::changeLanguage(const QString& langName) {
	QCoreApplication::removeTranslator(m_qtTranslator);
	m_qtTranslator->load("qt_" + langName, m_qtPath);
	QCoreApplication::installTranslator(m_qtTranslator);
	
	QCoreApplication::removeTranslator(m_Translator);
	m_Translator->load(langName, m_qmPath);
	QCoreApplication::installTranslator(m_Translator);
}

QString MyTranslatorClass::language() {
	return m_Translator->language();
}

MyTranslatorClass::~MyTranslatorClass() {
	delete m_qtTranslator;
	delete m_Translator;
}