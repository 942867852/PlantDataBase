#include "cplant.h"

CPlant::CPlant(const QString& name, const QString& description)
    : m_name(name), m_description(description)
{
}

QString CPlant::getName() const {
    return m_name;
}

QString CPlant::getDescription() const {
    return m_description;
}

void CPlant::addTag(const QString& tag) {
    if (!tag.isEmpty())
        m_tags.insert(tag);
}

void CPlant::removeTag(const QString& tag) {
    m_tags.remove(tag);
}

bool CPlant::hasTag(const QString& tag) const {
    return m_tags.contains(tag);
}

QSet<QString> CPlant::getTags() const {
    return m_tags;
}
