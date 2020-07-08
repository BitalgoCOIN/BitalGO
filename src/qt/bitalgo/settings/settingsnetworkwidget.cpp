//Copyright (c) 2019 The PIVX developers
//Copyright (c) 2020 The BitalGO developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "qt/bitalgo/settings/settingsnetworkwidget.h"
#include "qt/bitalgo/settings/forms/ui_settingsnetworkwidget.h"
#include "optionsmodel.h"
#include "qt/bitalgo/qtutils.h"

SettingsNetworkWidget::SettingsNetworkWidget(BitalGOGUI* _window, QWidget *parent) :
    PWidget(_window, parent),
    ui(new Ui::SettingsNetworkWidget)
{
    ui->setupUi(this);

    this->setStyleSheet(parent->styleSheet());

    // Containers
    ui->left->setProperty("cssClass", "container");
    ui->left->setContentsMargins(10,10,10,10);

    // Buttons
    ui->pushButtonSave->setText(tr("SAVE"));
    ui->pushButtonReset->setText(tr("Reset to default"));
    setCssBtnPrimary(ui->pushButtonSave);
    setCssBtnSecondary(ui->pushButtonReset);

    connect(ui->pushButtonSave, &QPushButton::clicked, [this] { Q_EMIT saveSettings(); });
}

void SettingsNetworkWidget::setMapper(QDataWidgetMapper *mapper){
}

SettingsNetworkWidget::~SettingsNetworkWidget()
{
    delete ui;
}
