#ifndef REQUESTDETAILSDLG_H
#define REQUESTDETAILSDLG_H

#include <QDialog>

class RequestDetailsDlg : public QDialog
{
    Q_OBJECT
public:
    explicit RequestDetailsDlg(QWidget *parent = 0);
    void setRequest(const QString& text);

signals:

public slots:
};

#endif // REQUESTDETAILSDLG_H
