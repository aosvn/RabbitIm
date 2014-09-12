#ifndef USERINFO_H
#define USERINFO_H

#include <QObject>
#include <QDate>
#include <QImage>
#include <QDataStream>
#include "qxmpp/QXmppPresence.h"
#include "qxmpp/QXmppVCardIq.h"

class CUserInfo : public QObject
{
    Q_OBJECT
public:
    explicit CUserInfo(QObject *parent = 0);

    virtual QString GetShowName();//根据配置显示用户名称  
    virtual QString GetName();
    virtual QString GetJid();
    virtual QString GetBareJid();
    virtual QString GetDomain();
    virtual QString GetResource();
    virtual QString GetNick();
    virtual QDate GetBirthday();
    virtual QString GetEmail();
    virtual QString GetDescription();
    virtual QImage GetPhoto();

#ifndef QT_NO_DATASTREAM
    friend QDataStream & operator <<(QDataStream &output, const CUserInfo &roster);
    friend QDataStream & operator >>(QDataStream &input, CUserInfo &roster);
#endif

    virtual int UpdateUserInfo(const QXmppVCardIq &vCard, QString jid);

protected:
    QString m_szJid;
    QString m_szName;
    QString m_szNick;
    QDate m_Birthday;
    QString m_szEmail;
    QString m_szDescription;
    QImage m_imgPhoto;

signals:
    
public slots:
    
};

#endif // USERINFO_H