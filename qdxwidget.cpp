/*
================================
 dxwidget.cpp

 Created on: 16 Feb 2014
 Author: Jan Holownia

 Copyright (c) Jan Holownia <jan.holownia@gmail.com> 2012.
================================
*/

#include "qdxwidget.h"

#include <QApplication>
#include <QResizeEvent>
#include <QDebug>

QDXWidget::QDXWidget(QWidget *parent) :
    QWidget(parent),
    m_d3d(nullptr)
{
    setAttribute(Qt::WA_PaintOnScreen);
    setAttribute(Qt::WA_NoSystemBackground);
}

QDXWidget::~QDXWidget()
{

}

bool QDXWidget::init()
{
    const bool vsyncEnabled = true;
    const float screenDepth = 1000.0f;
    const float screenNear = 0.1f;

    m_d3d.reset(new D3DBase);
    return m_d3d->init(width(), height(), vsyncEnabled, (HWND)winId(), false, screenDepth, screenNear);
}

void QDXWidget::update()
{
    m_d3d->beginScene(0.0f, 0.0f, 1.0f, 1.0f);

    m_d3d->endScene();
}

void QDXWidget::updateNow()
{
    if (!m_d3d.isNull())
    {
        update();
    }
    else
    {
        init();
    }

    updateLater();
}

void QDXWidget::updateLater()
{
    if (!m_updatePending)
    {
        m_updatePending = true;
        QCoreApplication::postEvent(this, new QEvent(QEvent::UpdateRequest));
    }
}

bool QDXWidget::event(QEvent *event)
{
    if (event->type() == QEvent::UpdateRequest)
    {
        m_updatePending = false;
        updateNow();
        return true;
    }
    else
    {
        return QWidget::event(event);
    }
}

void QDXWidget::resizeEvent(QResizeEvent *event)
{
    Q_UNUSED(event);
    m_d3d->resizeBuffers(width(), height());
}


