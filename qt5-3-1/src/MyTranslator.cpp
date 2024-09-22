#include "MyTranslator.h"

MyTranslator::MyTranslator(QApplication* _app, const QString& user_path) : 
	m_qmPath(user_path)
{
	m_qtTranslator = new QTranslator(_app);
	m_Translator = new QTranslator(_app);
	
	QString langName = QLocale::system().name();
	
#if (QT_VERSION >= QT_VERSION_CHECK(6, 0, 0))
	m_qtPath = QLibraryInfo::path(QLibraryInfo::TranslationsPath);
#else
	m_qtPath = QLibraryInfo::location(QLibraryInfo::TranslationsPath);
#endif
	
	if (m_qtTranslator->load("qt_" + langName, m_qtPath))
		_app->installTranslator(m_qtTranslator);
	
	if (m_Translator->load(langName, m_qmPath))
		_app->installTranslator(m_Translator);
}

void MyTranslator::changeLanguage(const QString& langName) {
	QCoreApplication::removeTranslator(m_qtTranslator);
	if (m_qtTranslator->load("qt_" + langName, m_qtPath))
		QCoreApplication::installTranslator(m_qtTranslator);
	
	QCoreApplication::removeTranslator(m_Translator);
	if (m_Translator->load(langName, m_qmPath))
		QCoreApplication::installTranslator(m_Translator);
}

const QString MyTranslator::language() {
	return m_Translator->language();
}

MyTranslator::~MyTranslator() {
	delete m_qtTranslator;
	delete m_Translator;
}