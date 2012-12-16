#ifndef ABOUTINFO_H
#define ABOUTINFO_H

#include "network/networkmanager.h"

class AccountInfo : public NetworkManager
{
public:
    enum EQueries
    {
      EUserInfoQuery = 0,
      EAboutInfoQuery
    };

    struct Data
    {
     QString name;
     QString email;
     QString domainSharingPolicy;
     QString permissionId;
     long quotaBytesTotal;
     long quotaBytesUsed;
     long quotaBytesUsedInTrash;
    };

    AccountInfo(const QString &uiq, const QString &aiq);

protected:
    void slotReplyFinished(QNetworkReply*);

public:
    void getInfo(void);

private:
    bool parseReply(const QString &str);

private:
    QString userInfoQuery;
    QString aboutInfoQuery;
    EQueries query;
    QString queryStr;
    Data accountData;
};

#endif // ABOUTINFO_H