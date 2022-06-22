/*
 * Copyright (C) 2020 ~ 2021 Uniontech Software Technology Co., Ltd.
 *
 * Author:     LiuMingHang <liuminghang@uniontech.com>
 *
 * Maintainer: ZhangYong <ZhangYong@uniontech.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "gtestview.h"
#include "accessibility/ac-desktop-define.h"
#include <DGuiApplicationHelper>
#include "imageviewer.h"
#include "imageengine.h"
#include "service/imagedataservice.h"
#include "viewpanel/navigationwidget.h"
#define  private public
#include "viewpanel/contents/imgviewlistview.h"


//view panel
TEST_F(gtestview, imgviewlistview)
{
    LibImgViewListView *widget = new LibImgViewListView();
    widget->resize(1090, 1080);
    widget->show();
    QTest::mouseMove(widget, QPoint(1000, 1075), 200);
    QTest::mouseMove(widget, QPoint(200, 500), 200);
    QTest::mousePress(widget,Qt::LeftButton, Qt::NoModifier, QPoint(200, 400), 200);
    QTest::mouseMove(widget, QPoint(20, 20), 200);
    QTest::mouseRelease(widget,Qt::LeftButton, Qt::NoModifier, QPoint(200, 400), 200);
    QTest::mouseDClick(widget, Qt::LeftButton, Qt::NoModifier, QPoint(20, 20), 200);

    widget->deleteLater();
    widget = nullptr;

}

TEST_F(gtestview, imgviewlistview_openNext_NULL)
{
    LibImgViewListView *widget = new LibImgViewListView();
    widget->resize(1090, 1080);
    widget->show();
    widget->openNext();

    widget->deleteLater();
    widget = nullptr;

}

TEST_F(gtestview, imgviewlistview_openpre_NULL)
{
    LibImgViewListView *widget = new LibImgViewListView();
    widget->resize(1090, 1080);
    widget->show();
    widget->openPre();

    widget->deleteLater();
    widget = nullptr;

}

TEST_F(gtestview, LibImgViewDelegate_setItemSize)
{
    LibImgViewDelegate *widget = new LibImgViewDelegate();
    widget->setItemSize(QSize(100,100));

    widget->deleteLater();
    widget = nullptr;

}
