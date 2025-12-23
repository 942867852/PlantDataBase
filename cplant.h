#ifndef CPLANT_H
#define CPLANT_H

#include <QString>
#include <QSet>

class CPlant
{
public:
    CPlant(const QString& name, const QString& description = "");

    // 获取基本信息
    QString getName() const;
    QString getDescription() const;

    // 标签操作
    void addTag(const QString& tag);
    void removeTag(const QString& tag);
    bool hasTag(const QString& tag) const;
    QSet<QString> getTags() const;

private:
    QString m_name;
    QString m_description;
    QSet<QString> m_tags;  // 存储所有习性标签
};

#endif // CPLANT_H
