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
#include "unionimage/baseutils.h"
#include "unionimage/imageutils.h"
#include "unionimage/imgoperate.h"
#include "unionimage/pluginbaseutils.h"
#include "unionimage/snifferimageformat.h"
#include "unionimage/unionimage.h"
#include "service/commonservice.h"


TEST_F(gtestview, baseutils_trashFileNull)
{
    bool bRet = Libutils::base::trashFile("xxx");
    EXPECT_EQ(false, bRet);
}

TEST_F(gtestview, baseutils_trashFilesvg)
{
    bool bRet = Libutils::base::trashFile(QApplication::applicationDirPath() + "/svg3.svg");
    EXPECT_EQ(true, bRet);
}

TEST_F(gtestview, baseutils_SpliteTextNull_true)
{
    Libutils::base::SpliteText("xxxxxxx", QFont(), 3, true);
}

TEST_F(gtestview, baseutils_SpliteTextNormal_true)
{
    Libutils::base::SpliteText("xxxxxxx", QFont(), 15, true);
}

TEST_F(gtestview, baseutils_SpliteTextNormal_false)
{
    Libutils::base::SpliteText("xxxxxxx", QFont(), 3, false);
}

TEST_F(gtestview, baseutils_SpliteTextNormal_fasle)
{
    Libutils::base::SpliteText("xxxxxxx", QFont(), 15, false);
}

TEST_F(gtestview, image_rotateNull90)
{
    bool bRet = Libutils::image::rotate("xxxx", 90);
    EXPECT_EQ(false, bRet);
}

TEST_F(gtestview, image_rotateNormal90)
{
    bool bRet = Libutils::image::rotate(QApplication::applicationDirPath() + "/test/jpg170.jpg", 90);
    EXPECT_EQ(true, bRet);
}

TEST_F(gtestview, image_rotateNull45)
{
    bool bRet = Libutils::image::rotate("xxxx", 45);
    EXPECT_EQ(false, bRet);
}

TEST_F(gtestview, image_rotateNormal45)
{
    bool bRet = Libutils::image::rotate(QApplication::applicationDirPath() + "/test/jpg170.jpg", 45);
    EXPECT_EQ(false, bRet);
}

TEST_F(gtestview, image_thumbnailExist)
{
    bool bRet = Libutils::image::thumbnailExist(QApplication::applicationDirPath() + "/test/jpg170.jpg");
    EXPECT_EQ(false, bRet);
}

TEST_F(gtestview, image_pluginbaseutilsNoraml)
{
    QMimeData data;
    QList <QUrl> list;
    list << QApplication::applicationDirPath() + "/test/jpg170.jpg";
    data.setUrls(list);
    bool bRet = pluginUtils::base::checkMimeData(&data);
    EXPECT_EQ(true, bRet);
}

TEST_F(gtestview, image_pluginbaseutilsNull)
{
    QMimeData data;
    bool bRet = pluginUtils::base::checkMimeData(&data);
    EXPECT_EQ(false, bRet);
}

TEST_F(gtestview, image_pluginbaseutilsDir)
{
    QMimeData data;
    QList <QUrl> list;
    list << QApplication::applicationDirPath() + "/test";
    data.setUrls(list);
    bool bRet = pluginUtils::base::checkMimeData(&data);
    if (LibCommonService::instance()->getImgViewerType() == imageViewerSpace::ImgViewerType::ImgViewerTypeAlbum) {
        EXPECT_EQ(true, bRet);
    } else {
        EXPECT_EQ(false, bRet);
    }
}

TEST_F(gtestview, image_pluginbaseutilsGif)
{
    QMimeData data;
    QList <QUrl> list;
    list << QApplication::applicationDirPath() + "/gif.gif";
    data.setUrls(list);
    bool bRet = pluginUtils::base::checkMimeData(&data);
    EXPECT_EQ(true, bRet);
}

TEST_F(gtestview, image_pluginbaseutilsMkMutiDir)
{
    pluginUtils::base::mkMutiDir(QApplication::applicationDirPath() + "/Mutidir");
}

TEST_F(gtestview, image_pluginbaseutilsgetImagesInfo)
{
    pluginUtils::base::getImagesInfo(QApplication::applicationDirPath());
}

TEST_F(gtestview, image_pluginbaseutilsgetImagesInfo_false)
{
    pluginUtils::base::getImagesInfo(QApplication::applicationDirPath(), false);
}

TEST_F(gtestview, image_imageSupportRead)
{
    pluginUtils::base::imageSupportRead(QApplication::applicationDirPath() + "/gif.gif");
}

TEST_F(gtestview, image_supportedImageFormats)
{
    pluginUtils::base::supportedImageFormats();
}
