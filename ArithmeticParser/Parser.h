#pragma once

#include <QSet>
#include "ArithmeticParser/OperationTable.h"
#include "ArithmeticParser/Interfaces/IParserTemplateMethod.h"

class Parser: public IParserTemplateMethod {
public:
    Parser();
    Parser(const OperationTable& table);
    virtual ~Parser() override;

    virtual QVariant parse(const QString&) const override;
    void setTable(const OperationTable& t) { table = t; }

protected:
    QString removeSpaces(const QString& str) const override;
    QVariant evalExpression(const QString & str, int & pos) const override;
    QVariant evalTerm(const QString &str, int & pos, int priority) const override;
    QVariant evalFactor(const QString &str, int &pos) const override;

    QVariant getFactor(const QString& str, int& pos) const override;

    OperationTable table;
};

