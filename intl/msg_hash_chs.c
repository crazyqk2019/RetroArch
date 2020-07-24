/*  RetroArch - A frontend for libretro.
 *  Copyright (C) 2011-2017 - Daniel De Matteis
 *  Copyright (C) 2016-2019 - Brad Parker
 *
 *  RetroArch is free software: you can redistribute it and/or modify it under the terms
 *  of the GNU General Public License as published by the Free Software Found-
 *  ation, either version 3 of the License, or (at your option) any later version.
 *
 *  RetroArch is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
 *  without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 *  PURPOSE.  See the GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License along with RetroArch.
 *  If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdio.h>
#include <stdint.h>
#include <stddef.h>

#include <compat/strl.h>
#include <string/stdstring.h>

#include "../msg_hash.h"
#include "../verbosity.h"

#ifdef RARCH_INTERNAL
#include "../configuration.h"

int msg_hash_get_help_chs_enum(enum msg_hash_enums msg, char *s, size_t len)
{
    settings_t *settings = config_get_ptr();

    if (msg == MENU_ENUM_LABEL_CONNECT_NETPLAY_ROOM)
    {
       snprintf(s, len,
             "TODO/FIXME - 在此输入信息。"
             );
       return 0;
    }
    if (msg <= MENU_ENUM_LABEL_INPUT_HOTKEY_BIND_END &&
        msg >= MENU_ENUM_LABEL_INPUT_HOTKEY_BIND_BEGIN)
    {
       unsigned idx = msg - MENU_ENUM_LABEL_INPUT_HOTKEY_BIND_BEGIN;

       switch (idx)
       {
          case RARCH_FAST_FORWARD_KEY:
             snprintf(s, len,
                   "在快进和正常速度之间切换。"
                   );
             break;
          case RARCH_FAST_FORWARD_HOLD_KEY:
             snprintf(s, len,
                   "按住快进。\n"
                   " \n"
                   "放开取消快进。"
                   );
             break;
          case RARCH_SLOWMOTION_KEY:
             snprintf(s, len,
                   "切换慢动作。");
             break;
          case RARCH_SLOWMOTION_HOLD_KEY:
             snprintf(s, len,
                   "按住启用慢动作。");
             break;
          case RARCH_PAUSE_TOGGLE:
             snprintf(s, len,
                   "在暂停和继续之间切换。");
             break;
          case RARCH_FRAMEADVANCE:
             snprintf(s, len,
                   "游戏暂停时以帧步进。");
             break;
          case RARCH_SHADER_NEXT:
             snprintf(s, len,
                   "应用目录中的下一个渲染器。");
             break;
          case RARCH_SHADER_PREV:
             snprintf(s, len,
                   "应用目录中的上一个渲染器。");
             break;
          case RARCH_CHEAT_INDEX_PLUS:
          case RARCH_CHEAT_INDEX_MINUS:
          case RARCH_CHEAT_TOGGLE:
             snprintf(s, len,
                   "作弊。");
             break;
          case RARCH_RESET:
             snprintf(s, len,
                   "复位游戏。");
             break;
          case RARCH_SCREENSHOT:
             snprintf(s, len,
                   "截取屏幕。");
             break;
          case RARCH_MUTE:
             snprintf(s, len,
                   "静音/取消静音。");
             break;
          case RARCH_OSK:
             snprintf(s, len,
                   "切换屏幕键盘。");
             break;
          case RARCH_FPS_TOGGLE:
             snprintf(s, len,
                   "切换帧率显示。");
             break;
          case RARCH_SEND_DEBUG_INFO:
             snprintf(s, len,
                   "发送诊断信息和RetroArch设置到我们的服务已帮助分析问题。");
             break;
          case RARCH_NETPLAY_HOST_TOGGLE:
             snprintf(s, len,
                   "切换网络主机模式开关。");
             break;
          case RARCH_NETPLAY_GAME_WATCH:
             snprintf(s, len,
                   "切换网络联机游戏/旁观者模式。");
             break;
          case RARCH_ENABLE_HOTKEY:
             snprintf(s, len,
                   "启用其他热键。\n"
                   " \n"
                   "如果此热键绑定到任一键盘键、手柄键或者方向键\n"
                   "所有其他热键只在此热键保持按下时生效。\n"
                   " \n"
                   "否则，所有键盘热键都被禁用。");
             break;
          case RARCH_VOLUME_UP:
             snprintf(s, len,
                   "提高音量。");
             break;
          case RARCH_VOLUME_DOWN:
             snprintf(s, len,
                   "降低音量。");
             break;
          case RARCH_OVERLAY_NEXT:
             snprintf(s, len,
                   "切换到下一个覆盖层，循环切换。");
             break;
          case RARCH_DISK_EJECT_TOGGLE:
             snprintf(s, len,
                   "弹出/收起光/磁盘。 \n"
                   " \n"
                   "用于多盘游戏。");
             break;
          case RARCH_DISK_NEXT:
          case RARCH_DISK_PREV:
             snprintf(s, len,
                   "切换光/磁盘，在弹出后使用。\n"
                   " \n"
                   "再次切换弹出以完成操作。");
             break;
          case RARCH_GRAB_MOUSE_TOGGLE:
             snprintf(s, len,
                   "切换鼠标捕获。\n"
                   " \n"
                   "鼠标被捕获时，RetroArch隐藏鼠标，\n"
                   "保持鼠标指针在窗口范围内以使鼠标相关输入\n"
                   "工作的更好。");
             break;
          case RARCH_GAME_FOCUS_TOGGLE:
             snprintf(s, len,
                   "切换游戏焦点。\n"
                   " \n"
                   "当游戏获得焦点是，RetroArch将禁用热键同时保持鼠标在窗口内。");
             break;
          case RARCH_MENU_TOGGLE:
             snprintf(s, len, "切换菜单。");
             break;
          case RARCH_LOAD_STATE_KEY:
             snprintf(s, len,
                   "载入及时存档。");
             break;
          case RARCH_FULLSCREEN_TOGGLE_KEY:
             snprintf(s, len,
                   "切换全屏。");
             break;
          case RARCH_QUIT_KEY:
             snprintf(s, len,
                   "正常退出RetroArch的按键。 \n"
                   " \n"
                   "通过强制方式（发送SIGKILL信号等）结束RetroArch运行\n"
                   "会导致无法保存游戏进度等信息。"
#ifdef __unix__
                   "\n在类Unix系统，SIGINT/SIGTERM信号可以允许正常退出。"
#endif
                   "");
             break;
          case RARCH_STATE_SLOT_PLUS:
          case RARCH_STATE_SLOT_MINUS:
             snprintf(s, len,
                   "及时存档槽位。\n"
                   " \n"
                   "槽位设为0时，存档文件名为*.state（或其他在命令行定义的名称）\n"
                   " \n"
                   "槽位设为非0时，路径将为<路径><d>，<d>为槽位号。");
             break;
          case RARCH_SAVE_STATE_KEY:
             snprintf(s, len,
                   "Saves state.");
             break;
          case RARCH_REWIND:
             snprintf(s, len,
                   "按住以回退。\n"
                   " \n"
                   "回退功能必须已启用。");
             break;
          case RARCH_BSV_RECORD_TOGGLE:
             snprintf(s, len,
                   "开始/暂停录制。");
             break;
          default:
             if (string_is_empty(s))
                strlcpy(s, msg_hash_to_str(MENU_ENUM_LABEL_VALUE_NO_INFORMATION_AVAILABLE), len);
             break;
       }

       return 0;
    }

    switch (msg)
    {
        case MENU_ENUM_LABEL_ACCOUNTS_RETRO_ACHIEVEMENTS:
            snprintf(s, len, "记录详细信息到你的Retro成就账号。\n"
                    " \n"
                    "访问retroachievements.org免费注册一个账号。\n"
                    " \n"
                    "注册完成后在RetroArch输入你的用户名和密码。");
            break;
        case MENU_ENUM_LABEL_CHEEVOS_USERNAME:
            snprintf(s, len, "你的Retro成就账号用户名。");
            break;
        case MENU_ENUM_LABEL_CHEEVOS_PASSWORD:
            snprintf(s, len, "你的Retro成就账号密码。");
            break;
        case MENU_ENUM_LABEL_USER_LANGUAGE:
            snprintf(s, len, "以选择的语言本地化显示菜单和所有屏幕消息。\n"
                    " \n"
                    "需要重启程序以生效。\n"
                    " \n"
                    "注意：并非所有语言当前都已实现。\n"
                    " \n"
                    "如果某个语言未实现，则使用英文显示。");
            break;
        case MENU_ENUM_LABEL_VIDEO_FONT_PATH:
            snprintf(s, len, "更改屏幕信息字体。");
            break;
        case MENU_ENUM_LABEL_GAME_SPECIFIC_OPTIONS:
            snprintf(s, len, "自动载入游戏特定内核设置。");
            break;
        case MENU_ENUM_LABEL_AUTO_OVERRIDES_ENABLE:
            snprintf(s, len, "自动载入覆盖设置。");
            break;
        case MENU_ENUM_LABEL_AUTO_REMAPS_ENABLE:
            snprintf(s, len, "自动载入输入重映射文件。");
            break;
        case MENU_ENUM_LABEL_SORT_SAVESTATES_ENABLE:
            snprintf(s, len, "在及时存档文件名前加上内核名称。");
            break;
        case MENU_ENUM_LABEL_SORT_SAVEFILES_ENABLE:
            snprintf(s, len, "在游戏存档文件名前加上内核名称。");
            break;
        case MENU_ENUM_LABEL_RESUME_CONTENT:
            snprintf(s, len, "退出菜单返回游戏。");
            break;
        case MENU_ENUM_LABEL_RESTART_CONTENT:
            snprintf(s, len, "从开头重新开始游戏。");
            break;
        case MENU_ENUM_LABEL_CLOSE_CONTENT:
            snprintf(s, len, "关闭游戏并从内存中卸载。");
            break;
        case MENU_ENUM_LABEL_UNDO_LOAD_STATE:
            snprintf(s, len, "如果已载入及时存档，游戏将恢复到存档载入之前的状态。");
            break;
        case MENU_ENUM_LABEL_UNDO_SAVE_STATE:
            snprintf(s, len, "如果一个及时存档被覆盖了，它将恢复到被覆盖之前的状态。");
            break;
        case MENU_ENUM_LABEL_TAKE_SCREENSHOT:
            snprintf(s, len, "创建屏幕截图。\n"
                    " \n"
                    "截图将保存在截图目录中。");
            break;
        case MENU_ENUM_LABEL_ADD_TO_FAVORITES:
            snprintf(s, len, "添加记录到收藏夹。");
            break;
        case MENU_ENUM_LABEL_RUN:
            snprintf(s, len, "开始游戏。");
            break;
        case MENU_ENUM_LABEL_INFORMATION:
            snprintf(s, len, "显示关于此游戏的附加信息。");
            break;
        case MENU_ENUM_LABEL_FILE_BROWSER_CONFIG:
            snprintf(s, len, "配置文件。");
            break;
        case MENU_ENUM_LABEL_FILE_BROWSER_COMPRESSED_ARCHIVE:
            snprintf(s, len, "压缩的文件。");
            break;
        case MENU_ENUM_LABEL_FILE_BROWSER_RECORD_CONFIG:
            snprintf(s, len, "录制配置文件。");
            break;
        case MENU_ENUM_LABEL_FILE_BROWSER_CURSOR:
            snprintf(s, len, "数据库游标文件。");
            break;
        case MENU_ENUM_LABEL_FILE_CONFIG:
            snprintf(s, len, "配置文件。");
            break;
        case MENU_ENUM_LABEL_SCAN_THIS_DIRECTORY:
            snprintf(s, len,
                     "选择此项在当前目录扫描游戏。");
            break;
        case MENU_ENUM_LABEL_USE_THIS_DIRECTORY:
            snprintf(s, len,
                     "选择此项设置为当前目录。");
            break;
        case MENU_ENUM_LABEL_CONTENT_DATABASE_DIRECTORY:
            snprintf(s, len,
                     "游戏数据库目录。\n"
                             " \n"
                             "指向游戏数据库的目录路径。");
            break;
        case MENU_ENUM_LABEL_THUMBNAILS_DIRECTORY:
            snprintf(s, len,
                     "预览图目录。\n"
                             " \n"
                             "用于保存预览图文件。");
            break;
        case MENU_ENUM_LABEL_LIBRETRO_INFO_PATH:
            snprintf(s, len,
                     "内核信息目录。\n"
                             " \n"
                             "查找内核信息文件的目录。");
            break;
        case MENU_ENUM_LABEL_PLAYLIST_DIRECTORY:
            snprintf(s, len,
                     "游戏列表目录。\n"
                             " \n"
                             "所有游戏列表文件保存在此目录。");
            break;
        case MENU_ENUM_LABEL_DUMMY_ON_CORE_SHUTDOWN:
            snprintf(s, len,
                     "某些内核可能有关机功能。\n"
                             " \n"
                             "如果此项禁用，选择内核的关闭的功能\n"
                             "可能导致RetroArch被关闭。\n"
                             " \n"
                             "启用此选项会载入一个空内核而不是关闭，\n"
                             "因此不会导致RetroArch被关闭。");
            break;
        case MENU_ENUM_LABEL_CHECK_FOR_MISSING_FIRMWARE:
            snprintf(s, len,
                     "某些可能需要固件或者BIOS文件。"
                             " \n"
                             "如果此项关闭，即使固件缺失也会尝试载入。\n");
            break;
        case MENU_ENUM_LABEL_PARENT_DIRECTORY:
            snprintf(s, len,
                     "返回父目录。");
            break;
        case MENU_ENUM_LABEL_FILE_BROWSER_OPEN_UWP_PERMISSIONS:
            snprintf(s, len,
                     "打开Windows权限设置，\n"
                     "以启用broadFileSystemAccess能力。");
            break;
        case MENU_ENUM_LABEL_FILE_BROWSER_OPEN_PICKER:
           snprintf(s, len,
                     "打开系统文件对话框以访问附加目录。");
           break;
        case MENU_ENUM_LABEL_FILE_BROWSER_SHADER_PRESET:
            snprintf(s, len,
                     "渲染器预设文件。");
            break;
        case MENU_ENUM_LABEL_FILE_BROWSER_SHADER:
            snprintf(s, len,
                     "渲染器文件");
            break;
        case MENU_ENUM_LABEL_FILE_BROWSER_REMAP:
            snprintf(s, len,
                     "控制器重映射文件。");
            break;
        case MENU_ENUM_LABEL_FILE_BROWSER_CHEAT:
            snprintf(s, len,
                     "作弊码文件。");
            break;
        case MENU_ENUM_LABEL_FILE_BROWSER_OVERLAY:
            snprintf(s, len,
                     "覆盖层文件。");
            break;
        case MENU_ENUM_LABEL_FILE_BROWSER_RDB:
            snprintf(s, len,
                     "数据库文件。");
            break;
        case MENU_ENUM_LABEL_FILE_BROWSER_FONT:
            snprintf(s, len,
                     "TrueType字体文件。");
            break;
        case MENU_ENUM_LABEL_FILE_BROWSER_PLAIN_FILE:
            snprintf(s, len,
                     "一般文件。");
            break;
        case MENU_ENUM_LABEL_FILE_BROWSER_MOVIE_OPEN:
            snprintf(s, len,
                     "视频。\n"
                             " \n"
                             "选择此项用视频播放器打开此文件。");
            break;
        case MENU_ENUM_LABEL_FILE_BROWSER_MUSIC_OPEN:
            snprintf(s, len,
                     "音乐。\n"
                             " \n"
                             "选择此项用音乐播放器打开此文件。");
            break;
        case MENU_ENUM_LABEL_FILE_BROWSER_IMAGE:
            snprintf(s, len,
                     "图像文件。");
            break;
        case MENU_ENUM_LABEL_FILE_BROWSER_IMAGE_OPEN_WITH_VIEWER:
            snprintf(s, len,
                     "图像。 \n"
                             " \n"
                             "选择此项用图像查看器打开此文件。");
            break;
        case MENU_ENUM_LABEL_FILE_BROWSER_CORE_SELECT_FROM_COLLECTION:
            snprintf(s, len,
                     "Libretro内核。 \n"
                             " \n"
                             "选择此项将关联此内核到游戏。");
            break;
        case MENU_ENUM_LABEL_FILE_BROWSER_CORE:
            snprintf(s, len,
                     "Libretro内核。 \n"
                             " \n"
                             "选择此项将载入此内核。");
            break;
        case MENU_ENUM_LABEL_FILE_BROWSER_DIRECTORY:
            snprintf(s, len,
                     "目录。\n"
                             " \n"
                             "选择此项打开此目录。");
            break;
        case MENU_ENUM_LABEL_CACHE_DIRECTORY:
            snprintf(s, len,
                     "缓存目录。\n"
                             " \n"
                             "RetroArch解压缩临时文件到此目录。");
            break;
        case MENU_ENUM_LABEL_HISTORY_LIST_ENABLE:
            snprintf(s, len,
                     "如果启用，载入的每个游戏都会被添加到历史列表。");
            break;
        case MENU_ENUM_LABEL_RGUI_BROWSER_DIRECTORY:
            snprintf(s, len,
                     "文件浏览器目录。\n"
                             " \n"
                             "设置文件浏览器起始目录。");
            break;
        case MENU_ENUM_LABEL_INPUT_POLL_TYPE_BEHAVIOR:
            snprintf(s, len,
                     "影响RetroArch内部如何轮询输入。\n"
                             " \n"
                             "提前 - 输入轮询在每帧处理之前。\n"
                             "正常 - 输入轮询在轮询被请求时。\n"
                             "滞后 - 输入轮询在每帧首次输入状态被请求时。\n"
                             " \n"
                             "根据配置的不同，设为“提前”或者“滞后”\n"
                             "可能会有更低的延迟。\n\n"
                             "联机游戏时忽略此项。"
            );
            break;
        case MENU_ENUM_LABEL_INPUT_DESCRIPTOR_HIDE_UNBOUND:
            snprintf(s, len,
                     "隐藏内核未设置的输入描述符。");
            break;
        case MENU_ENUM_LABEL_VIDEO_REFRESH_RATE:
            snprintf(s, len,
                     "显示器的刷新率。\n"
                             "用于选择合适的音频输入频率。");
            break;
        case MENU_ENUM_LABEL_VIDEO_FORCE_SRGB_DISABLE:
            snprintf(s, len,
                     "强制禁用sRGB FBO支持。 Some Intel \n"
                             "sRGB FBO支持打开时，Windows下的OpenGL驱动会有视频问题");
            break;
        case MENU_ENUM_LABEL_AUDIO_ENABLE:
            snprintf(s, len,
                     "启用音频输出。");
            break;
        case MENU_ENUM_LABEL_AUDIO_SYNC:
            snprintf(s, len,
                     "同步音频（推荐）。");
            break;
        case MENU_ENUM_LABEL_AUDIO_LATENCY:
            snprintf(s, len,
                     "期望的音频延迟，以毫秒计。\n"
                             "如果音频驱动不能提供给定的延迟，此项可能不起作用。");
            break;
        case MENU_ENUM_LABEL_VIDEO_ALLOW_ROTATE:
            snprintf(s, len,
                     "允许内核设置旋转。\n"
                             "如果禁用，旋转请求被接收，但是被忽略。\n\n"
                             "用于手工旋转显示器的情况。");
            break;
        case MENU_ENUM_LABEL_INPUT_DESCRIPTOR_LABEL_SHOW:
            snprintf(s, len,
                     "显示内核设置的输入描述符，而不是缺省值。");
            break;
        case MENU_ENUM_LABEL_CONTENT_HISTORY_SIZE:
            snprintf(s, len,
                     "游戏历史列表的最大记录数。");
            break;
        case MENU_ENUM_LABEL_VIDEO_WINDOWED_FULLSCREEN:
            snprintf(s, len,
                     "全屏时是否使用窗口模式。");
            break;
        case MENU_ENUM_LABEL_VIDEO_FONT_SIZE:
            snprintf(s, len,
                     "屏幕信息的字体大小。");
            break;
        case MENU_ENUM_LABEL_SAVESTATE_AUTO_INDEX:
            snprintf(s, len,
                     "每次保存后自动增加槽位号，\n"
                             "生成多个存档文件。\n"
                             "载入游戏时，槽位号自动设为最大值（最后一次存档位）");
            break;
        case MENU_ENUM_LABEL_FPS_SHOW:
            snprintf(s, len,
                     "显示当前帧率。");
            break;
        case MENU_ENUM_LABEL_MEMORY_SHOW:
            snprintf(s, len,
                     "显示帧数的同时显示当前内存使用量/总量。");
            break;
        case MENU_ENUM_LABEL_VIDEO_FONT_ENABLE:
            snprintf(s, len,
                     "显示/隐藏屏幕信息。");
            break;
        case MENU_ENUM_LABEL_VIDEO_MESSAGE_POS_X:
        case MENU_ENUM_LABEL_VIDEO_MESSAGE_POS_Y:
            snprintf(s, len,
                     "在屏幕上显示信息的位置。\n"
                             "取值范围[0.0, 1.0]。");
            break;
        case MENU_ENUM_LABEL_INPUT_OVERLAY_ENABLE:
            snprintf(s, len,
                     "启用或禁用当前覆盖层。");
            break;
        case MENU_ENUM_LABEL_INPUT_OVERLAY_HIDE_IN_MENU:
            snprintf(s, len,
                     "在菜单中隐藏当前覆盖层。");
            break;
        case MENU_ENUM_LABEL_INPUT_OVERLAY_SHOW_PHYSICAL_INPUTS:
            snprintf(s, len,
                      "在屏幕覆盖层显示键盘/控制器按钮。");
            break;
        case MENU_ENUM_LABEL_INPUT_OVERLAY_SHOW_PHYSICAL_INPUTS_PORT:
            snprintf(s, len,
                      "选择在屏幕覆盖层显示的控制器端口。");
            break;
        case MENU_ENUM_LABEL_OVERLAY_PRESET:
            snprintf(s, len,
                     "指向输入覆盖层的路径。");
            break;
        case MENU_ENUM_LABEL_OVERLAY_OPACITY:
            snprintf(s, len,
                     "覆盖层不透明度。");
            break;
        case MENU_ENUM_LABEL_VIDEO_LAYOUT_ENABLE:
            snprintf(s, len,
                     "启用或禁用当前视频布局。");
            break;
        case MENU_ENUM_LABEL_VIDEO_LAYOUT_PATH:
            snprintf(s, len,
                     "指向视频覆盖层的路径。");
            break;
        case MENU_ENUM_LABEL_VIDEO_LAYOUT_SELECTED_VIEW:
            snprintf(s, len,
                     "布局可以包含多个视图。\n"
                     "选择一个视图。");
            break;
        case MENU_ENUM_LABEL_INPUT_BIND_TIMEOUT:
            snprintf(s, len,
                     "输入绑定超时（秒）。\n"
                             "处理下一个绑定前等待的秒数。");
            break;
        case MENU_ENUM_LABEL_INPUT_BIND_HOLD:
            snprintf(s, len,
               "输入绑定按住时长（秒）。\n"
               "保持按住以完成绑定的时间。");
            break;
        case MENU_ENUM_LABEL_OVERLAY_SCALE:
            snprintf(s, len,
                     "覆盖层缩放。");
            break;
        case MENU_ENUM_LABEL_AUDIO_OUTPUT_RATE:
            snprintf(s, len,
                     "音频输出采样率。");
            break;
        case MENU_ENUM_LABEL_VIDEO_SHARED_CONTEXT:
            snprintf(s, len,
                     "开启此项，如果硬件渲染内核应该拥有自己的私有上下文。\n"
                             "避免假定硬件状态会在每帧之间更改。"
            );
            break;
        case MENU_ENUM_LABEL_CORE_LIST:
            snprintf(s, len,
                     "载入内核。\n"
                             " \n"
                             "浏览内核。浏览器初始目录取决于“内核目录”设置。\n"
                             "如果为空，将从根目录开始。\n"
                             " \n"
                             "如果“内核目录”是一个目录，将会作为顶级目录。\n"
                             "如果“内核目录”是一个全路径文件名， 将会从该文件所在目录开始。");
            break;
        case MENU_ENUM_LABEL_VALUE_MENU_ENUM_CONTROLS_PROLOG:
            snprintf(s, len,
                     "您可以通过手柄或键盘用下面的设置来控制菜单。\n"
                             " \n"
            );
            break;
        case MENU_ENUM_LABEL_WELCOME_TO_RETROARCH:
            snprintf(s, len,
                     "欢迎来到RetroArch\n"
            );
            break;
        case MENU_ENUM_LABEL_VALUE_HELP_AUDIO_VIDEO_TROUBLESHOOTING_DESC: {
            /* Work around C89 limitations */
            char u[501];
            const char *t =
                    "RetroArch依赖于特定的音频/视频同步形式，\n"
                            "这需要和显示器刷新率进行校准，\n"
                            "以获得最佳的性能。\n"
                            " \n"
                            "如果您经历到音频爆音视频撕裂，\n"
                            "通常意味着您需要进行校准设置。\n"
                            "下面是一些选择：\n"
                            " \n";
            snprintf(u, sizeof(u), /* can't inline this due to the printf arguments */
                     "a) 前往'%s' -> '%s'，启用“多线程视频处理”。\n"
                             "刷新率在这个模式无关紧要。\n"
                             "帧率会较高，但是视频可能不太平滑。\n"
                             "b) 前往'%s' -> '%s'，查看'%s'。\n"
                             "让它运行2048帧，然后点击“确定”。",
                     msg_hash_to_str(MENU_ENUM_LABEL_VALUE_SETTINGS),
                     msg_hash_to_str(MENU_ENUM_LABEL_VALUE_VIDEO_SETTINGS),
                     msg_hash_to_str(MENU_ENUM_LABEL_VALUE_SETTINGS),
                     msg_hash_to_str(MENU_ENUM_LABEL_VALUE_VIDEO_SETTINGS),
                     msg_hash_to_str(MENU_ENUM_LABEL_VALUE_VIDEO_REFRESH_RATE_AUTO));
            strlcpy(s, t, len);
            strlcat(s, u, len);
        }
            break;
        case MENU_ENUM_LABEL_VALUE_HELP_SCANNING_CONTENT_DESC:
            snprintf(s, len,
                     "要扫描游戏，前往'%s'然后选择'%s'或%s'。\n"
                             "\n"
                             "文件会和数据库中的记录相比较。\n"
                             "如果匹配，将会添加到游戏列表。\n"
                             "\n"
                             "之后您可以前往'%s' -> '%s'运行该游戏，\n"
                             "而不需要每次通过文件浏览器运行。\n"
                             "\n"
                             "注意：某些内核游戏可能还无法扫描。",
                     msg_hash_to_str(MENU_ENUM_LABEL_VALUE_ADD_CONTENT_LIST),
                     msg_hash_to_str(MENU_ENUM_LABEL_VALUE_SCAN_DIRECTORY),
                     msg_hash_to_str(MENU_ENUM_LABEL_VALUE_SCAN_FILE),
                     msg_hash_to_str(MENU_ENUM_LABEL_VALUE_LOAD_CONTENT_LIST),
                     msg_hash_to_str(MENU_ENUM_LABEL_VALUE_PLAYLISTS_TAB)
            );
            break;
        case MENU_ENUM_LABEL_VALUE_EXTRACTING_PLEASE_WAIT:
            snprintf(s, len,
                     "欢迎来到RetroArch\n"
                             "\n"
                             "正在解压资源，请稍等。\n"
                             "这可能需要一段时间...\n"
            );
            break;
        case MENU_ENUM_LABEL_INPUT_DRIVER:
            {
               const char *lbl = settings ? settings->arrays.input_driver : NULL;

               if (string_is_equal(lbl, msg_hash_to_str(MENU_ENUM_LABEL_INPUT_DRIVER_UDEV)))
                     snprintf(s, len,
                           "udev输入驱动。\n"
                           " \n"
                           "使用最新的evdev手柄API来支持摇杆。\n"
                           "它支持热拔插和力反馈。\n"
                           " \n"
                           "此驱动读取evdev事件以支持键盘。\n"
                           "它也支持键盘回调函数，鼠标和触摸板。\n"
                           " \n"
                           "缺省情况下在大多数Linux发行版里，\n"
                            "/dev/input节点只能被root访问（mode 600）\n"
                           "您可以通过设置一条udev规则来使之可以被非root用户访问。"
                           );
               else if (string_is_equal(lbl,
                        msg_hash_to_str(MENU_ENUM_LABEL_INPUT_DRIVER_LINUXRAW)))
                     snprintf(s, len,
                           "linuxraw输入驱动。\n"
                           " \n"
                           "此驱动需要一个活动的TTY。\n"
                           "键盘事件直接从TTY读取，更加简单但是不如udev自由。\n"
                           "鼠标等设备则根本不支持。\n"
                           " \n"
                           "此驱动使用旧式的摇杆API（/dev/input/js*）。");
               else
                     snprintf(s, len,
                           "输入驱动。\n"
                           " \n"
                           "根据视频驱动，可能需要强制使用一个不同的输入驱动。");
            }
            break;
        case MENU_ENUM_LABEL_LOAD_CONTENT_LIST:
            snprintf(s, len,
                     "载入游戏。\n"
                             "浏览游戏。\n"
                             " \n"
                             "要载入游戏，您需要一个“内核”以及一个游戏文件。\n"
                             " \n"
                             "要控制菜单从哪里开始浏览游戏，\n"
                             "请设置“文件浏览器目录”。\n"
                             "如果未设置，则从根目录开始。\n"
                             " \n"
                             "浏览器会过滤出当前已载入内核支持的文件，\n"
                             "并且使用当前内核运行选择的游戏。"
            );
            break;
        case MENU_ENUM_LABEL_LOAD_CONTENT_HISTORY:
            snprintf(s, len,
                     "从历史记录载入游戏。\n"
                             " \n"
                             "一旦游戏运行过，游戏和内核组合会保存在历史记录。\n"
                             " \n"
                             "历史记录文件保存在RetroArch设置文件同一目录下。\n"
                             "如果启动时未加载配置文件，历史文件也不会被保存或载入，\n"
                             "也不会出现在主菜单。"
            );
            break;
        case MENU_ENUM_LABEL_VIDEO_DRIVER:
            {
               const char *video_driver = settings->arrays.video_driver;

               snprintf(s, len,
                     "当前视频驱动。");

               if (string_is_equal(video_driver, "gl"))
               {
                  snprintf(s, len,
                        "OpenGL视频驱动。\n"
                        " \n"
                        "此驱动允许软件渲染内核和libretro GL内核被使用。\n"
                        " \n"
                        "软件渲染内核和GL内核的性能取决于显卡的底层GL驱动。");
               }
               else if (string_is_equal(video_driver, "sdl2"))
               {
                  snprintf(s, len,
                        "SDL 2视频驱动。\n"
                        " \n"
                        "这是一个SDL 2软件渲染视频驱动。\n"
                        " \n"
                        "软件渲染内核的性能取决于平台的SDL实现。\n");
               }
               else if (string_is_equal(video_driver, "sdl1"))
               {
                  snprintf(s, len,
                        "SDL视频驱动。\n"
                        " \n"
                        "这是一个SDL 1.2 软件渲染视频驱动 software-rendered video \n"
                        "driver.\n"
                        " \n"
                        "性能不是最佳的，只考虑作为最后的选择使用。");
               }
               else if (string_is_equal(video_driver, "d3d"))
               {
                  snprintf(s, len,
                        "Direct3D视频驱动。\n"
                        " \n"
                        "软件渲染内核的性能取决于显卡的底层D3D驱动。");
               }
               else if (string_is_equal(video_driver, "exynos"))
               {
                  snprintf(s, len,
                        "Exynos-G2D视频驱动。\n"
                        " \n"
                        "这是一个底层Exynos视频驱动。\n"
                        "使用三星Exynos SoC的G2D单元做位块传输操作。\n"
                        " \n"
                        "软件渲染内核的性能应是优化的。");
               }
               else if (string_is_equal(video_driver, "drm"))
               {
                  snprintf(s, len,
                        "平面DRM视频驱动。\n"
                        " \n"
                        "这是一个底层视频驱动，\n"
                        "使用libdrm库通过GPU覆盖层进行硬件缩放。");
               }
               else if (string_is_equal(video_driver, "sunxi"))
               {
                  snprintf(s, len,
                        "Sunxi-G2D视频驱动。\n"
                        " \n"
                        "这是一个底层的Sunxi视频驱动。\n"
                        "使用Allwinner SoC的G2D单元。");
               }
            }
            break;
        case MENU_ENUM_LABEL_AUDIO_DSP_PLUGIN:
            snprintf(s, len,
                     "音频DSP插件。\n"
                             "在发送到驱动程序之前对音频进行处理。"
            );
            break;
        case MENU_ENUM_LABEL_AUDIO_RESAMPLER_DRIVER:
            {
               const char *lbl = settings ? settings->arrays.audio_resampler : NULL;

               if (string_is_equal(lbl, msg_hash_to_str(
                           MENU_ENUM_LABEL_AUDIO_RESAMPLER_DRIVER_SINC)))
                  strlcpy(s,
                        "窗口化正弦实现。", len);
               else if (string_is_equal(lbl, msg_hash_to_str(
                           MENU_ENUM_LABEL_AUDIO_RESAMPLER_DRIVER_CC)))
                  strlcpy(s,
                        "卷积余弦实现。", len);
               else if (string_is_empty(s))
                  strlcpy(s, msg_hash_to_str(MENU_ENUM_LABEL_VALUE_NO_INFORMATION_AVAILABLE), len);
            }
            break;

		case MENU_ENUM_LABEL_CRT_SWITCH_RESOLUTION: snprintf(s, len, "SET CRT");
			break;

		case MENU_ENUM_LABEL_CRT_SWITCH_RESOLUTION_SUPER: snprintf(s, len, "SET CRT SUPER");
			break;

        case MENU_ENUM_LABEL_VIDEO_SHADER_PRESET:
            snprintf(s, len,
                     "载入渲染器预设。\n"
                             " \n"
                             "直接载入渲染器预设。\n"
                             "渲染器菜单相应更新。\n"
                             " \n"
                             "如果CGP使用了非简单缩放（例如源缩放、X/Y轴相同缩放比例），\n"
                             "显示在菜单上的缩放比例可能不正确。"
            );
            break;
        case MENU_ENUM_LABEL_VIDEO_SHADER_SCALE_PASS:
            snprintf(s, len,
                     "此遍处理过程的缩放。\n"
                             " \n"
                             "缩放比例会累加。例如，第一次2x，第二次2x，\n"
                             "那么总缩放将是4x。\n"
                             " \n"
                             "如果最后一次处理过程有一个缩放因子，\n"
                             "那么结果是扩展到屏幕并且使用“缺省滤镜”处理。\n"
                             " \n"
                             "如果设为“任意”，那么1x缩放或者扩展到全屏都可能被使用，\n"
                             "这取决于这是不是最后一次处理过程。"
            );
            break;
        case MENU_ENUM_LABEL_VIDEO_SHADER_NUM_PASSES:
            snprintf(s, len,
                     "渲染处器理过程。\n"
                             " \n"
                             "RetroArch允许混合和匹配不同的渲染器，渲染任意次数，\n"
                             "使用自定义硬件滤镜以及缩放因子。\n"
                             " \n"
                             "这个选项指定渲染过程次数。\n"
                             "如果设为0，选择应用渲染器更改，将得到一个空渲染器。\n"
                             " \n"
                             "缺省滤镜选项会影响放大滤镜。");
            break;
        case MENU_ENUM_LABEL_VIDEO_SHADER_PARAMETERS:
            snprintf(s, len,
                     "渲染器参数。\n"
                             " \n"
                             "直接修改当前渲染器。不会保存到CGP/GLSLP预设文件。");
            break;
        case MENU_ENUM_LABEL_VIDEO_SHADER_PRESET_PARAMETERS:
            snprintf(s, len,
                     "渲染器预设参数。\n"
                             " \n"
                             "修改当前菜单中的渲染器预设。"
            );
            break;
        case MENU_ENUM_LABEL_VIDEO_SHADER_PASS:
            snprintf(s, len,
                     "渲染器路径。\n"
                             " \n"
                             "所有渲染器必须是同一类型（例如CG，GLSL或HLSL）。\n"
                             " \n"
                             "设置“渲染器目录”来决定浏览器从何处开始搜寻渲染器。"
            );
            break;
        case MENU_ENUM_LABEL_CONFIGURATION_SETTINGS:
            snprintf(s, len,
                     "确定配置文件优先级顺序和如何载入。");
            break;
        case MENU_ENUM_LABEL_CONFIG_SAVE_ON_EXIT:
            snprintf(s, len,
                     "退出时保存设置文件。\n"
                             "对于菜单模式很有用，因为设置可能被更改。\n"
                             "覆盖设置文件。\n"
                             " \n"
                             "#include和注释不会被保留。\n"
                             " \n"
                             "设计上，设置文件被认为是稳定不变的，\n"
                             "通常由用户维护而不应该在用户不\n"
                             "知情的情况下被改写。"
#if defined(RARCH_CONSOLE) || defined(RARCH_MOBILE)
            "\n然而，在控制台上情况并非如此，\n"
            "手动查看配置文件实际上不是一种选择。"
#endif
            );
            break;
        case MENU_ENUM_LABEL_CONFIRM_ON_EXIT:
            snprintf(s, len, "确定要退出吗？");
            break;
        case MENU_ENUM_LABEL_SHOW_HIDDEN_FILES:
            snprintf(s, len, "Show hidden files\n"
                    "and folders.");
            break;
        case MENU_ENUM_LABEL_VIDEO_SHADER_FILTER_PASS:
            snprintf(s, len,
                     "Hardware filter for this pass. \n"
                             " \n"
                             "If 'Don't Care' is set, 'Default \n"
                             "Filter' will be used."
            );
            break;
        case MENU_ENUM_LABEL_AUTOSAVE_INTERVAL:
            snprintf(s, len,
                     "Autosaves the non-volatile SRAM \n"
                             "at a regular interval.\n"
                             " \n"
                             "This is disabled by default unless set \n"
                             "otherwise. The interval is measured in \n"
                             "seconds. \n"
                             " \n"
                             "A value of 0 disables autosave.");
            break;
        case MENU_ENUM_LABEL_INPUT_BIND_DEVICE_TYPE:
            snprintf(s, len,
                     "Input Device Type. \n"
                             " \n"
                             "Picks which device type to use. This is \n"
                             "relevant for the libretro core itself."
            );
            break;
        case MENU_ENUM_LABEL_LIBRETRO_LOG_LEVEL:
            snprintf(s, len,
                     "Sets log level for libretro cores \n"
                             "(GET_LOG_INTERFACE). \n"
                             " \n"
                             " If a log level issued by a libretro \n"
                             " core is below libretro_log level, it \n"
                             " is ignored.\n"
                             " \n"
                             " DEBUG logs are always ignored unless \n"
                             " verbose mode is activated (--verbose).\n"
                             " \n"
                             " DEBUG = 0\n"
                             " INFO  = 1\n"
                             " WARN  = 2\n"
                             " ERROR = 3"
            );
            break;
        case MENU_ENUM_LABEL_STATE_SLOT_INCREASE:
        case MENU_ENUM_LABEL_STATE_SLOT_DECREASE:
            snprintf(s, len,
                     "State slots.\n"
                             " \n"
                             " With slot set to 0, save state name is *.state \n"
                             " (or whatever defined on commandline).\n"
                             "When slot is != 0, path will be (path)(d), \n"
                             "where (d) is slot number.");
            break;
        case MENU_ENUM_LABEL_SHADER_APPLY_CHANGES:
            snprintf(s, len,
                     "Apply Shader Changes. \n"
                             " \n"
                             "After changing shader settings, use this to \n"
                             "apply changes. \n"
                             " \n"
                             "Changing shader settings is a somewhat \n"
                             "expensive operation so it has to be \n"
                             "done explicitly. \n"
                             " \n"
                             "When you apply shaders, the menu shader \n"
                             "settings are saved to a temporary file (either \n"
                             "menu.cgp or menu.glslp) and loaded. The file \n"
                             "persists after RetroArch exits. The file is \n"
                             "saved to Shader Directory."
            );
            break;
        case MENU_ENUM_LABEL_SHADER_WATCH_FOR_CHANGES:
            snprintf(s, len,
                     "Watch shader files for new changes. \n"
                     " \n"
                     "After saving changes to a shader on disk, \n"
                     "it will automatically be recompiled \n"
                     "and applied to the running content."
            );
            break;
        case MENU_ENUM_LABEL_MENU_TOGGLE:
            snprintf(s, len,
                     "Toggles menu.");
            break;
        case MENU_ENUM_LABEL_GRAB_MOUSE_TOGGLE:
            snprintf(s, len,
                     "Toggles mouse grab.\n"
                             " \n"
                             "When mouse is grabbed, RetroArch hides the \n"
                             "mouse, and keeps the mouse pointer inside \n"
                             "the window to allow relative mouse input to \n"
                             "work better.");
            break;
        case MENU_ENUM_LABEL_GAME_FOCUS_TOGGLE:
            snprintf(s, len,
                     "Toggles game focus.\n"
                             " \n"
                             "When a game has focus, RetroArch will both disable \n"
                             "hotkeys and keep/warp the mouse pointer inside the window.");
            break;
        case MENU_ENUM_LABEL_DISK_NEXT:
            snprintf(s, len,
                     "Cycles through disk images. Use after \n"
                             "ejecting. \n"
                             " \n"
                             " Complete by toggling eject again.");
            break;
        case MENU_ENUM_LABEL_VIDEO_FILTER:
#ifdef HAVE_FILTERS_BUILTIN
            snprintf(s, len,
                  "CPU-based video filter.");
#else
            snprintf(s, len,
                     "CPU-based video filter.\n"
                             " \n"
                             "Path to a dynamic library.");
#endif
            break;
        case MENU_ENUM_LABEL_AUDIO_DEVICE:
            snprintf(s, len,
                     "Override the default audio device \n"
                             "the audio driver uses.\n"
                             "This is driver dependent. E.g.\n"
#ifdef HAVE_ALSA
            " \n"
            "ALSA wants a PCM device."
#endif
#ifdef HAVE_OSS
            " \n"
            "OSS wants a path (e.g. /dev/dsp)."
#endif
#ifdef HAVE_JACK
            " \n"
            "JACK wants portnames (e.g. system:playback1\n"
            ",system:playback_2)."
#endif
#ifdef HAVE_RSOUND
            " \n"
            "RSound wants an IP address to an RSound \n"
            "server."
#endif
            );
            break;
        case MENU_ENUM_LABEL_DISK_EJECT_TOGGLE:
            snprintf(s, len,
                     "Toggles eject for disks.\n"
                             " \n"
                             "Used for multiple-disk content.");
            break;
        case MENU_ENUM_LABEL_ENABLE_HOTKEY:
            snprintf(s, len,
                     "Enable other hotkeys.\n"
                             " \n"
                             " If this hotkey is bound to either keyboard, \n"
                             "joybutton or joyaxis, all other hotkeys will \n"
                             "be disabled unless this hotkey is also held \n"
                             "at the same time. \n"
                             " \n"
                             "This is useful for RETRO_KEYBOARD centric \n"
                             "implementations which query a large area of \n"
                             "the keyboard, where it is not desirable that \n"
                             "hotkeys get in the way.");
            break;
        case MENU_ENUM_LABEL_REWIND_ENABLE:
            snprintf(s, len,
                     "Enable rewinding.\n"
                             " \n"
                             "This will take a performance hit, \n"
                             "so it is disabled by default.");
            break;
        case MENU_ENUM_LABEL_CHEAT_APPLY_AFTER_TOGGLE:
            snprintf(s, len,
                     "Apply cheat immediately after toggling.");
            break;
        case MENU_ENUM_LABEL_CHEAT_APPLY_AFTER_LOAD:
            snprintf(s, len,
                     "Auto-apply cheats when game loads.");
            break;
        case MENU_ENUM_LABEL_LIBRETRO_DIR_PATH:
            snprintf(s, len,
                     "Core Directory. \n"
                             " \n"
                             "A directory for where to search for \n"
                             "libretro core implementations.");
            break;
        case MENU_ENUM_LABEL_VIDEO_REFRESH_RATE_AUTO:
            snprintf(s, len,
                     "Refresh Rate Auto.\n"
                             " \n"
                             "The accurate refresh rate of our monitor (Hz).\n"
                             "This is used to calculate audio input rate with \n"
                             "the formula: \n"
                             " \n"
                             "audio_input_rate = game input rate * display \n"
                             "refresh rate / game refresh rate\n"
                             " \n"
                             "If the implementation does not report any \n"
                             "values, NTSC defaults will be assumed for \n"
                             "compatibility.\n"
                             " \n"
                             "This value should stay close to 60Hz to avoid \n"
                             "large pitch changes. If your monitor does \n"
                             "not run at 60Hz, or something close to it, \n"
                             "disable VSync, and leave this at its default.");
            break;
        case MENU_ENUM_LABEL_VIDEO_REFRESH_RATE_POLLED:
            snprintf(s, len,
                     "Set Polled Refresh Rate\n"
                             " \n"
                            "Sets the refresh rate to the actual value\n"
                            "polled from the display driver.");
            break;
        case MENU_ENUM_LABEL_VIDEO_ROTATION:
            snprintf(s, len,
                     "Forces a certain rotation \n"
                             "of the screen.\n"
                             " \n"
                             "The rotation is added to rotations which\n"
                             "the libretro core sets (see Video Allow\n"
                             "Rotate).");
            break;
        case MENU_ENUM_LABEL_VIDEO_SCALE:
            snprintf(s, len,
                     "Fullscreen resolution.\n"
                             " \n"
                             "Resolution of 0 uses the \n"
                             "resolution of the environment.\n");
            break;
        case MENU_ENUM_LABEL_FASTFORWARD_RATIO:
            snprintf(s, len,
                     "Fastforward ratio.\n"
                             " \n"
                             "The maximum rate at which content will\n"
                             "be run when using fast forward.\n"
                             " \n"
                             " (E.g. 5.0 for 60 fps content => 300 fps \n"
                             "cap).\n"
                             " \n"
                             "RetroArch will go to sleep to ensure that \n"
                             "the maximum rate will not be exceeded.\n"
                             "Do not rely on this cap to be perfectly \n"
                             "accurate.");
            break;
        case MENU_ENUM_LABEL_VRR_RUNLOOP_ENABLE:
            snprintf(s, len,
                     "Sync to Exact Content Framerate.\n"
                             " \n"
                             "This option is the equivalent of forcing x1 speed\n"
                             "while still allowing fast forward.\n"
                             "No deviation from the core requested refresh rate,\n"
                             "no sound Dynamic Rate Control.");
            break;
        case MENU_ENUM_LABEL_VIDEO_MONITOR_INDEX:
            snprintf(s, len,
                     "Which monitor to prefer.\n"
                             " \n"
                             "0 (default) means no particular monitor \n"
                             "is preferred, 1 and up (1 being first \n"
                             "monitor), suggests RetroArch to use that \n"
                             "particular monitor.");
            break;
        case MENU_ENUM_LABEL_VIDEO_CROP_OVERSCAN:
            snprintf(s, len,
                     "Forces cropping of overscanned \n"
                             "frames.\n"
                             " \n"
                             "Exact behavior of this option is \n"
                             "core-implementation specific.");
            break;
        case MENU_ENUM_LABEL_VIDEO_SCALE_INTEGER:
            snprintf(s, len,
                     "Only scales video in integer \n"
                             "steps.\n"
                             " \n"
                             "The base size depends on system-reported \n"
                             "geometry and aspect ratio.\n"
                             " \n"
                             "If Force Aspect is not set, X/Y will be \n"
                             "integer scaled independently.");
            break;
        case MENU_ENUM_LABEL_AUDIO_VOLUME:
            snprintf(s, len,
                     "Audio volume, expressed in dB.\n"
                             " \n"
                             " 0 dB is normal volume. No gain will be applied.\n"
                             "Gain can be controlled in runtime with Input\n"
                             "Volume Up / Input Volume Down.");
            break;
        case MENU_ENUM_LABEL_AUDIO_RATE_CONTROL_DELTA:
            snprintf(s, len,
                     "Audio rate control.\n"
                             " \n"
                             "Setting this to 0 disables rate control.\n"
                             "Any other value controls audio rate control \n"
                             "delta.\n"
                             " \n"
                             "Defines how much input rate can be adjusted \n"
                             "dynamically.\n"
                             " \n"
                             " Input rate is defined as: \n"
                             " input rate * (1.0 +/- (rate control delta))");
            break;
        case MENU_ENUM_LABEL_AUDIO_MAX_TIMING_SKEW:
            snprintf(s, len,
                     "Maximum audio timing skew.\n"
                             " \n"
                             "Defines the maximum change in input rate.\n"
                             "You may want to increase this to enable\n"
                             "very large changes in timing, for example\n"
                             "running PAL cores on NTSC displays, at the\n"
                             "cost of inaccurate audio pitch.\n"
                             " \n"
                             " Input rate is defined as: \n"
                             " input rate * (1.0 +/- (max timing skew))");
            break;
        case MENU_ENUM_LABEL_OVERLAY_NEXT:
            snprintf(s, len,
                     "Toggles to next overlay.\n"
                             " \n"
                             "Wraps around.");
            break;
        case MENU_ENUM_LABEL_LOG_VERBOSITY:
            snprintf(s, len,
                     "Enable or disable verbosity level \n"
                             "of frontend.");
            break;
        case MENU_ENUM_LABEL_VOLUME_UP:
            snprintf(s, len,
                     "Increases audio volume.");
            break;
        case MENU_ENUM_LABEL_VOLUME_DOWN:
            snprintf(s, len,
                     "Decreases audio volume.");
            break;
        case MENU_ENUM_LABEL_VIDEO_DISABLE_COMPOSITION:
            snprintf(s, len,
                     "Forcibly disable composition.\n"
                             "Only valid on Windows Vista/7 for now.");
            break;
        case MENU_ENUM_LABEL_PERFCNT_ENABLE:
            snprintf(s, len,
                     "Enable or disable frontend \n"
                             "performance counters.");
            break;
        case MENU_ENUM_LABEL_SYSTEM_DIRECTORY:
            snprintf(s, len,
                     "System Directory. \n"
                             " \n"
                             "Sets the 'system' directory.\n"
                             "Cores can query for this\n"
                             "directory to load BIOSes, \n"
                             "system-specific configs, etc.");
            break;
        case MENU_ENUM_LABEL_SAVESTATE_AUTO_SAVE:
        case MENU_ENUM_LABEL_SAVESTATE_AUTO_LOAD:
            snprintf(s, len,
                     "Automatically saves a savestate at the \n"
                             "end of RetroArch's lifetime.\n"
                             " \n"
                             "RetroArch will automatically load any savestate\n"
                             "with this path on startup if 'Auto Load State\n"
                             "is enabled.");
            break;
        case MENU_ENUM_LABEL_VIDEO_THREADED:
            snprintf(s, len,
                     "Use threaded video driver.\n"
                             " \n"
                             "Using this might improve performance at the \n"
                             "possible cost of latency and more video \n"
                             "stuttering.");
            break;
        case MENU_ENUM_LABEL_VIDEO_VSYNC:
            snprintf(s, len,
                     "Video V-Sync.\n");
            break;
        case MENU_ENUM_LABEL_VIDEO_HARD_SYNC:
            snprintf(s, len,
                     "Attempts to hard-synchronize \n"
                             "CPU and GPU.\n"
                             " \n"
                             "Can reduce latency at the cost of \n"
                             "performance.");
            break;
        case MENU_ENUM_LABEL_REWIND_GRANULARITY:
            snprintf(s, len,
                     "Rewind granularity.\n"
                             " \n"
                             " When rewinding defined number of \n"
                             "frames, you can rewind several frames \n"
                             "at a time, increasing the rewinding \n"
                             "speed.");
            break;
        case MENU_ENUM_LABEL_REWIND_BUFFER_SIZE:
            snprintf(s, len,
                     "Rewind buffer size (MB).\n"
                             " \n"
                             " The amount of memory in MB to reserve \n"
                             "for rewinding.  Increasing this value \n"
                             "increases the rewind history length.\n");
            break;
        case MENU_ENUM_LABEL_REWIND_BUFFER_SIZE_STEP:
            snprintf(s, len,
                     "Rewind buffer size step (MB).\n"
                             " \n"
                             " Each time you increase or decrease \n"
                             "the rewind buffer size value via this \n"
                             "UI it will change by this amount.\n");
            break;
        case MENU_ENUM_LABEL_SCREENSHOT:
            snprintf(s, len,
                     "Take screenshot.");
            break;
        case MENU_ENUM_LABEL_VIDEO_FRAME_DELAY:
            snprintf(s, len,
                     "Sets how many milliseconds to delay\n"
                             "after VSync before running the core.\n"
                             "\n"
                             "Can reduce latency at the cost of\n"
                             "higher risk of stuttering.\n"
                             " \n"
                             "Maximum is 15.");
            break;
        case MENU_ENUM_LABEL_VIDEO_SHADER_DELAY:
            snprintf(s, len,
                     "Sets by how many milliseconds auto-loading shaders\n"
                             "are delayed.\n"
                             "\n"
                             "Can work around graphical glitches due to using\n"
                             "'screen grabbing' software like streaming software.");
            break;
        case MENU_ENUM_LABEL_VIDEO_HARD_SYNC_FRAMES:
            snprintf(s, len,
                     "Sets how many frames CPU can \n"
                             "run ahead of GPU when using 'GPU \n"
                             "Hard Sync'.\n"
                             " \n"
                             "Maximum is 3.\n"
                             " \n"
                             " 0: Syncs to GPU immediately.\n"
                             " 1: Syncs to previous frame.\n"
                             " 2: Etc ...");
            break;
        case MENU_ENUM_LABEL_VIDEO_BLACK_FRAME_INSERTION:
            snprintf(s, len,
                     "Inserts a black frame inbetween \n"
                             "frames.\n"
                             " \n"
                             "Useful for 120 Hz monitors who want to \n"
                             "play 60 Hz material with eliminated \n"
                             "ghosting.\n"
                             " \n"
                             "Video refresh rate should still be \n"
                             "configured as if it is a 60 Hz monitor \n"
                             "(divide refresh rate by 2).");
            break;
        case MENU_ENUM_LABEL_RGUI_SHOW_START_SCREEN:
            snprintf(s, len,
                     "Show startup screen in menu.\n"
                             "Is automatically set to false when seen\n"
                             "for the first time.\n"
                             " \n"
                             "This is only updated in config if\n"
                             "'Save Configuration on Exit' is enabled.\n");
            break;
        case MENU_ENUM_LABEL_VIDEO_FULLSCREEN:
            snprintf(s, len, "Toggles fullscreen.");
            break;
        case MENU_ENUM_LABEL_BLOCK_SRAM_OVERWRITE:
            snprintf(s, len,
                     "Block SRAM from being overwritten \n"
                             "when loading save states.\n"
                             " \n"
                             "Might potentially lead to buggy games.");
            break;
        case MENU_ENUM_LABEL_PAUSE_NONACTIVE:
            snprintf(s, len,
                     "Pause gameplay when window focus \n"
                             "is lost.");
            break;
        case MENU_ENUM_LABEL_VIDEO_GPU_SCREENSHOT:
            snprintf(s, len,
                     "Screenshots output of GPU shaded \n"
                             "material if available.");
            break;
        case MENU_ENUM_LABEL_SCREENSHOT_DIRECTORY:
            snprintf(s, len,
                     "Screenshot Directory. \n"
                             " \n"
                             "Directory to dump screenshots to."
            );
            break;
        case MENU_ENUM_LABEL_VIDEO_SWAP_INTERVAL:
            snprintf(s, len,
                     "VSync Swap Interval.\n"
                             " \n"
                             "Uses a custom swap interval for VSync. Set this \n"
                             "to effectively halve monitor refresh rate.");
            break;
        case MENU_ENUM_LABEL_SAVEFILE_DIRECTORY:
            snprintf(s, len,
                     "Savefile Directory. \n"
                             " \n"
                             "Save all save files (*.srm) to this \n"
                             "directory. This includes related files like \n"
                             ".bsv, .rt, .psrm, etc...\n"
                             " \n"
                             "This will be overridden by explicit command line\n"
                             "options.");
            break;
        case MENU_ENUM_LABEL_SAVESTATE_DIRECTORY:
            snprintf(s, len,
                     "Savestate Directory. \n"
                             " \n"
                             "Save all save states (*.state) to this \n"
                             "directory.\n"
                             " \n"
                             "This will be overridden by explicit command line\n"
                             "options.");
            break;
        case MENU_ENUM_LABEL_ASSETS_DIRECTORY:
            snprintf(s, len,
                     "Assets Directory. \n"
                             " \n"
                             " This location is queried by default when \n"
                             "menu interfaces try to look for loadable \n"
                             "assets, etc.");
            break;
        case MENU_ENUM_LABEL_DYNAMIC_WALLPAPERS_DIRECTORY:
            snprintf(s, len,
                     "Dynamic Wallpapers Directory. \n"
                             " \n"
                             " The place to store backgrounds that will \n"
                             "be loaded dynamically by the menu depending \n"
                             "on context.");
            break;
        case MENU_ENUM_LABEL_SLOWMOTION_RATIO:
            snprintf(s, len,
                     "Slowmotion ratio."
                             " \n"
                             "When slowmotion, content will slow\n"
                             "down by factor.");
            break;
        case MENU_ENUM_LABEL_INPUT_BUTTON_AXIS_THRESHOLD:
            snprintf(s, len,
                     "Defines the axis threshold.\n"
                             " \n"
                             "How far an axis must be tilted to result\n"
                             "in a button press.\n"
                             " Possible values are [0.0, 1.0].");
            break;
        case MENU_ENUM_LABEL_INPUT_TURBO_PERIOD:
            snprintf(s, len,
                     "Turbo period.\n"
                             " \n"
                             "Describes the period of which turbo-enabled\n"
                             "buttons toggle.\n"
                             " \n"
                             "Numbers are described in frames."
            );
            break;
        case MENU_ENUM_LABEL_INPUT_TURBO_MODE:
            snprintf(s, len,
                  "Turbo Mode.\n"
                  " \n"
                  "Selects the general behavior of turbo mode."
                  );
            break;
        case MENU_ENUM_LABEL_INPUT_TURBO_DEFAULT_BUTTON:
            snprintf(s, len,
                  "Turbo Default Button.\n"
                  " \n"
                  "Default active button for Turbo Mode 'Single Button'.\n"
                  );
            break;
        case MENU_ENUM_LABEL_INPUT_DUTY_CYCLE:
            snprintf(s, len,
                     "Duty cycle.\n"
                             " \n"
                             "Describes how long the period of a turbo-enabled\n"
                             "should be.\n"
                             " \n"
                             "Numbers are described in frames."
            );
            break;
        case MENU_ENUM_LABEL_INPUT_TOUCH_ENABLE:
            snprintf(s, len, "Enable touch support.");
            break;
        case MENU_ENUM_LABEL_INPUT_PREFER_FRONT_TOUCH:
            snprintf(s, len, "Use front instead of back touch.");
            break;
        case MENU_ENUM_LABEL_MOUSE_ENABLE:
            snprintf(s, len, "Enable mouse input inside the menu.");
            break;
        case MENU_ENUM_LABEL_POINTER_ENABLE:
            snprintf(s, len, "Enable touch input inside the menu.");
            break;
        case MENU_ENUM_LABEL_MENU_WALLPAPER:
            snprintf(s, len, "Path to an image to set as the background.");
            break;
        case MENU_ENUM_LABEL_NAVIGATION_WRAPAROUND:
            snprintf(s, len,
                     "Wrap-around to beginning and/or end \n"
                             "if boundary of list is reached \n"
                             "horizontally and/or vertically.");
            break;
        case MENU_ENUM_LABEL_PAUSE_LIBRETRO:
            snprintf(s, len,
                     "If disabled, the game will keep \n"
                             "running in the background when we are in the \n"
                             "menu.");
            break;
        case MENU_ENUM_LABEL_SUSPEND_SCREENSAVER_ENABLE:
            snprintf(s, len,
                     "Suspends the screensaver. Is a hint that \n"
                             "does not necessarily have to be \n"
                             "honored by the video driver.");
            break;
        case MENU_ENUM_LABEL_NETPLAY_MODE:
            snprintf(s, len,
                     "Netplay client mode for the current user. \n"
                             "Will be 'Server' mode if disabled.");
            break;
        case MENU_ENUM_LABEL_NETPLAY_DELAY_FRAMES:
            snprintf(s, len,
                     "The amount of delay frames to use for netplay. \n"
                             " \n"
                             "Increasing this value will increase \n"
                             "performance, but introduce more latency.");
            break;
        case MENU_ENUM_LABEL_NETPLAY_PUBLIC_ANNOUNCE:
            snprintf(s, len,
                     "Whether to announce netplay games publicly. \n"
                             " \n"
                             "If set to false, clients must manually connect \n"
                             "rather than using the public lobby.");
            break;
        case MENU_ENUM_LABEL_NETPLAY_START_AS_SPECTATOR:
            snprintf(s, len,
                     "Whether to start netplay in spectator mode. \n"
                             " \n"
                             "If set to true, netplay will be in spectator mode \n"
                             "on start. It's always possible to change mode \n"
                             "later.");
            break;
        case MENU_ENUM_LABEL_NETPLAY_ALLOW_SLAVES:
            snprintf(s, len,
                     "Whether to allow connections in slave mode. \n"
                             " \n"
                             "Slave-mode clients require very little processing \n"
                             "power on either side, but will suffer \n"
                             "significantly from network latency.");
            break;
        case MENU_ENUM_LABEL_NETPLAY_REQUIRE_SLAVES:
            snprintf(s, len,
                     "Whether to disallow connections not in slave mode. \n"
                             " \n"
                             "Not recommended except for very fast networks \n"
                             "with very weak machines. \n");
            break;
        case MENU_ENUM_LABEL_NETPLAY_STATELESS_MODE:
            snprintf(s, len,
                     "Whether to run netplay in a mode not requiring\n"
                             "save states. \n"
                             " \n"
                             "If set to true, a very fast network is required,\n"
                             "but no rewinding is performed, so there will be\n"
                             "no netplay jitter.\n");
            break;
        case MENU_ENUM_LABEL_NETPLAY_CHECK_FRAMES:
            snprintf(s, len,
                     "The frequency in frames with which netplay \n"
                             "will verify that the host and client are in \n"
                             "sync. \n"
                             " \n"
                             "With most cores, this value will have no \n"
                             "visible effect and can be ignored. With \n"
                             "nondeterminstic cores, this value determines \n"
                             "how often the netplay peers will be brought \n"
                             "into sync. With buggy cores, setting this \n"
                             "to any non-zero value will cause severe \n"
                             "performance issues. Set to zero to perform \n"
                             "no checks. This value is only used on the \n"
                             "netplay host. \n");
            break;
        case MENU_ENUM_LABEL_NETPLAY_INPUT_LATENCY_FRAMES_MIN:
            snprintf(s, len,
                     "The number of frames of input latency for \n"
                     "netplay to use to hide network latency. \n"
                     " \n"
                     "When in netplay, this option delays local \n"
                     "input, so that the frame being run is \n"
                     "closer to the frames being received from \n"
                     "the network. This reduces jitter and makes \n"
                     "netplay less CPU-intensive, but at the \n"
                     "price of noticeable input lag. \n");
            break;
        case MENU_ENUM_LABEL_NETPLAY_INPUT_LATENCY_FRAMES_RANGE:
            snprintf(s, len,
                     "The range of frames of input latency that \n"
                     "may be used by netplay to hide network \n"
                     "latency. \n"
                     "\n"
                     "If set, netplay will adjust the number of \n"
                     "frames of input latency dynamically to \n"
                     "balance CPU time, input latency and \n"
                     "network latency. This reduces jitter and \n"
                     "makes netplay less CPU-intensive, but at \n"
                     "the price of unpredictable input lag. \n");
            break;
        case MENU_ENUM_LABEL_NETPLAY_NAT_TRAVERSAL:
            snprintf(s, len,
                     "When hosting, attempt to listen for\n"
                             "connections from the public internet, using\n"
                             "UPnP or similar technologies to escape LANs. \n");
            break;
        case MENU_ENUM_LABEL_NETPLAY_USE_MITM_SERVER:
            snprintf(s, len,
                     "When hosting a netplay session, relay connection through a \n"
                             "man-in-the-middle server \n"
                             "to get around firewalls or NAT/UPnP issues. \n");
            break;
        case MENU_ENUM_LABEL_NETPLAY_MITM_SERVER:
            snprintf(s, len,
                     "Specifies the man-in-the-middle server \n"
                             "to use for netplay. A server that is \n"
                             "located closer to you may have less latency. \n");
            break;
        case MENU_ENUM_LABEL_VIDEO_MAX_SWAPCHAIN_IMAGES:
            snprintf(s, len,
                     "Maximum amount of swapchain images. This \n"
                             "can tell the video driver to use a specific \n"
                             "video buffering mode. \n"
                             " \n"
                             "Single buffering - 1\n"
                             "Double buffering - 2\n"
                             "Triple buffering - 3\n"
                             " \n"
                             "Setting the right buffering mode can have \n"
                             "a big impact on latency.");
            break;
        case MENU_ENUM_LABEL_VIDEO_SMOOTH:
            snprintf(s, len,
                     "Smoothens picture with bilinear filtering. \n"
                             "Should be disabled if using shaders.");
            break;
      case MENU_ENUM_LABEL_VIDEO_CTX_SCALING:
         snprintf(s, len,
#ifdef HAVE_ODROIDGO2
               "RGA scaling and bicubic filtering. May break widgets."
#else
               "Hardware context scaling (if available)."
#endif
         );
         break;
        case MENU_ENUM_LABEL_TIMEDATE_ENABLE:
            snprintf(s, len,
                     "Shows current date and/or time inside menu.");
            break;
        case MENU_ENUM_LABEL_TIMEDATE_STYLE:
           snprintf(s, len,
              "Style to show the current date and/or time in.");
           break;
        case MENU_ENUM_LABEL_BATTERY_LEVEL_ENABLE:
            snprintf(s, len,
                     "Shows current battery level inside menu.");
            break;
        case MENU_ENUM_LABEL_CORE_ENABLE:
            snprintf(s, len,
                     "Shows current core inside menu.");
            break;
        case MENU_ENUM_LABEL_NETPLAY_ENABLE_HOST:
            snprintf(s, len,
                     "Enables Netplay in host (server) mode.");
            break;
        case MENU_ENUM_LABEL_NETPLAY_ENABLE_CLIENT:
            snprintf(s, len,
                     "Enables Netplay in client mode.");
            break;
        case MENU_ENUM_LABEL_NETPLAY_DISCONNECT:
            snprintf(s, len,
                     "Disconnects an active Netplay connection.");
            break;
        case MENU_ENUM_LABEL_NETPLAY_LAN_SCAN_SETTINGS:
            snprintf(s, len,
                     "Search for and connect to netplay hosts on the local network.");
            break;
        case MENU_ENUM_LABEL_NETPLAY_SETTINGS:
            snprintf(s, len,
                     "Setting related to Netplay.");
            break;
        case MENU_ENUM_LABEL_DYNAMIC_WALLPAPER:
            snprintf(s, len,
                     "Dynamically load a new background \n"
                             "depending on context.");
            break;
        case MENU_ENUM_LABEL_CORE_UPDATER_BUILDBOT_URL:
            snprintf(s, len,
                     "URL to core updater directory on the \n"
                             "Libretro buildbot.");
            break;
        case MENU_ENUM_LABEL_BUILDBOT_ASSETS_URL:
            snprintf(s, len,
                     "URL to assets updater directory on the \n"
                             "Libretro buildbot.");
            break;
        case MENU_ENUM_LABEL_INPUT_REMAP_BINDS_ENABLE:
            snprintf(s, len,
                     "if enabled, overrides the input binds \n"
                             "with the remapped binds set for the \n"
                             "current core.");
            break;
        case MENU_ENUM_LABEL_OVERLAY_DIRECTORY:
            snprintf(s, len,
                     "Overlay Directory. \n"
                             " \n"
                             "Defines a directory where overlays are \n"
                             "kept for easy access.");
            break;
        case MENU_ENUM_LABEL_VIDEO_LAYOUT_DIRECTORY:
            snprintf(s, len,
                     "Video Layout Directory. \n"
                             " \n"
                             "Defines a directory where video layouts are \n"
                             "kept for easy access.");
            break;
        case MENU_ENUM_LABEL_INPUT_MAX_USERS:
            snprintf(s, len,
                     "Maximum amount of users supported by \n"
                             "RetroArch.");
            break;
        case MENU_ENUM_LABEL_CORE_UPDATER_AUTO_EXTRACT_ARCHIVE:
            snprintf(s, len,
                     "After downloading, automatically extract \n"
                             "archives that the downloads are contained \n"
                             "inside.");
            break;
        case MENU_ENUM_LABEL_NAVIGATION_BROWSER_FILTER_SUPPORTED_EXTENSIONS_ENABLE:
            snprintf(s, len,
                     "Filter files being shown by \n"
                             "supported extensions.");
            break;
        case MENU_ENUM_LABEL_NETPLAY_NICKNAME:
            snprintf(s, len,
                     "The username of the person running RetroArch. \n"
                             "This will be used for playing online games.");
            break;
        case MENU_ENUM_LABEL_NETPLAY_TCP_UDP_PORT:
            snprintf(s, len,
                     "The port of the host IP address. \n"
                             "Can be either a TCP or UDP port.");
            break;
        case MENU_ENUM_LABEL_NETPLAY_SPECTATOR_MODE_ENABLE:
            snprintf(s, len,
                     "Enable or disable spectator mode for \n"
                             "the user during netplay.");
            break;
        case MENU_ENUM_LABEL_NETPLAY_IP_ADDRESS:
            snprintf(s, len,
                     "The address of the host to connect to.");
            break;
        case MENU_ENUM_LABEL_NETPLAY_PASSWORD:
            snprintf(s, len,
                     "The password for connecting to the netplay \n"
                             "host. Used only in host mode.");
            break;
        case MENU_ENUM_LABEL_NETPLAY_SPECTATE_PASSWORD:
            snprintf(s, len,
                     "The password for connecting to the netplay \n"
                             "host with only spectator privileges. Used \n"
                             "only in host mode.");
            break;
        case MENU_ENUM_LABEL_STDIN_CMD_ENABLE:
            snprintf(s, len,
                     "Enable stdin command interface.");
            break;
        case MENU_ENUM_LABEL_UI_COMPANION_START_ON_BOOT:
            snprintf(s, len,
                     "Start User Interface companion driver \n"
                             "on boot (if available).");
            break;
        case MENU_ENUM_LABEL_MENU_DRIVER:
            snprintf(s, len, "Menu driver to use.");
            break;
        case MENU_ENUM_LABEL_INPUT_MENU_ENUM_TOGGLE_GAMEPAD_COMBO:
            snprintf(s, len,
                     "Gamepad button combination to toggle menu. \n"
                             " \n"
                             "0 - None \n"
                             "1 - Press L + R + Y + D-Pad Down \n"
                             "simultaneously. \n"
                             "2 - Press L3 + R3 simultaneously. \n"
                             "3 - Press Start + Select simultaneously.");
            break;
        case MENU_ENUM_LABEL_INPUT_ALL_USERS_CONTROL_MENU:
            snprintf(s, len, "Allows any user to control the menu. \n"
                    " \n"
                    "When disabled, only user 1 can control the menu.");
            break;
        case MENU_ENUM_LABEL_INPUT_AUTODETECT_ENABLE:
            snprintf(s, len,
                     "Enable input auto-detection.\n"
                             " \n"
                             "Will attempt to auto-configure \n"
                             "joypads, Plug-and-Play style.");
            break;
        case MENU_ENUM_LABEL_CAMERA_ALLOW:
            snprintf(s, len,
                     "Allow or disallow camera access by \n"
                             "cores.");
            break;
        case MENU_ENUM_LABEL_LOCATION_ALLOW:
            snprintf(s, len,
                     "Allow or disallow location services \n"
                             "access by cores.");
            break;
        case MENU_ENUM_LABEL_TURBO:
            snprintf(s, len,
                     "Turbo enable.\n"
                             " \n"
                             "Holding the turbo while pressing another \n"
                             "button will let the button enter a turbo \n"
                             "mode where the button state is modulated \n"
                             "with a periodic signal. \n"
                             " \n"
                             "The modulation stops when the button \n"
                             "itself (not turbo button) is released.");
            break;
        case MENU_ENUM_LABEL_OSK_ENABLE:
            snprintf(s, len,
                     "Enable/disable on-screen keyboard.");
            break;
        case MENU_ENUM_LABEL_AUDIO_MUTE:
            snprintf(s, len,
                     "Mute/unmute audio.");
            break;
        case MENU_ENUM_LABEL_REWIND:
            snprintf(s, len,
                     "Hold button down to rewind.\n"
                             " \n"
                             "Rewind must be enabled.");
            break;
        case MENU_ENUM_LABEL_EXIT_EMULATOR:
            snprintf(s, len,
                     "Key to exit RetroArch cleanly."
#if !defined(RARCH_MOBILE) && !defined(RARCH_CONSOLE)
                            "\nKilling it in any hard way (SIGKILL, \n"
                            "etc) will terminate without saving\n"
                            "RAM, etc. On Unix-likes,\n"
                            "SIGINT/SIGTERM allows\n"
                            "a clean deinitialization."
#endif
            );
            break;
        case MENU_ENUM_LABEL_LOAD_STATE:
            snprintf(s, len,
                     "Loads state.");
            break;
        case MENU_ENUM_LABEL_SAVE_STATE:
            snprintf(s, len,
                     "Saves state.");
            break;
        case MENU_ENUM_LABEL_NETPLAY_GAME_WATCH:
            snprintf(s, len,
                     "Netplay toggle play/spectate mode.");
            break;
        case MENU_ENUM_LABEL_CHEAT_INDEX_PLUS:
            snprintf(s, len,
                     "Increment cheat index.\n");
            break;
        case MENU_ENUM_LABEL_CHEAT_INDEX_MINUS:
            snprintf(s, len,
                     "Decrement cheat index.\n");
            break;
        case MENU_ENUM_LABEL_SHADER_PREV:
            snprintf(s, len,
                     "Applies previous shader in directory.");
            break;
        case MENU_ENUM_LABEL_SHADER_NEXT:
            snprintf(s, len,
                     "Applies next shader in directory.");
            break;
        case MENU_ENUM_LABEL_RESET:
            snprintf(s, len,
                     "Reset the content.\n");
            break;
        case MENU_ENUM_LABEL_PAUSE_TOGGLE:
            snprintf(s, len,
                     "Toggle between paused and non-paused state.");
            break;
        case MENU_ENUM_LABEL_CHEAT_TOGGLE:
            snprintf(s, len,
                     "Toggle cheat index.\n");
            break;
        case MENU_ENUM_LABEL_CHEAT_IDX:
            snprintf(s, len,
                     "Index position in list.\n");
            break;
        case MENU_ENUM_LABEL_CHEAT_ADDRESS_BIT_POSITION:
            snprintf(s, len,
                     "Address bitmask when Memory Search Size < 8-bit.\n");
            break;
        case MENU_ENUM_LABEL_CHEAT_REPEAT_COUNT:
            snprintf(s, len,
                     "The number of times the cheat will be applied.\nUse with the other two Iteration options to affect large areas of memory.");
            break;
        case MENU_ENUM_LABEL_CHEAT_REPEAT_ADD_TO_ADDRESS:
            snprintf(s, len,
                     "After each 'Number of Iterations' the Memory Address will be increased by this number times the 'Memory Search Size'.");
            break;
        case MENU_ENUM_LABEL_CHEAT_REPEAT_ADD_TO_VALUE:
            snprintf(s, len,
                     "After each 'Number of Iterations' the Value will be increased by this amount.");
            break;
        case MENU_ENUM_LABEL_CHEAT_MATCH_IDX:
            snprintf(s, len,
                     "Select the match to view.");
            break;
        case MENU_ENUM_LABEL_CHEAT_START_OR_CONT:
            snprintf(s, len,
                     "Scan memory to create new cheats");
            break;
        case MENU_ENUM_LABEL_CHEAT_START_OR_RESTART:
            snprintf(s, len,
                     "Left/Right to change bit-size\n");
            break;
        case MENU_ENUM_LABEL_CHEAT_SEARCH_EXACT:
            snprintf(s, len,
                     "Left/Right to change value\n");
            break;
        case MENU_ENUM_LABEL_CHEAT_SEARCH_LT:
            snprintf(s, len,
                     " ");
            break;
        case MENU_ENUM_LABEL_CHEAT_SEARCH_GT:
            snprintf(s, len,
                     " ");
            break;
        case MENU_ENUM_LABEL_CHEAT_SEARCH_EQ:
            snprintf(s, len,
                     " ");
            break;
        case MENU_ENUM_LABEL_CHEAT_SEARCH_NEQ:
            snprintf(s, len,
                     " ");
            break;
        case MENU_ENUM_LABEL_CHEAT_SEARCH_EQPLUS:
            snprintf(s, len,
                     "Left/Right to change value\n");
            break;
        case MENU_ENUM_LABEL_CHEAT_SEARCH_EQMINUS:
            snprintf(s, len,
                     "Left/Right to change value\n");
            break;
        case MENU_ENUM_LABEL_CHEAT_ADD_MATCHES:
            snprintf(s, len,
                     " ");
            break;
        case MENU_ENUM_LABEL_CHEAT_VIEW_MATCHES:
            snprintf(s, len,
                     " ");
            break;
        case MENU_ENUM_LABEL_CHEAT_CREATE_OPTION:
            snprintf(s, len,
                     " ");
            break;
        case MENU_ENUM_LABEL_CHEAT_DELETE_OPTION:
            snprintf(s, len,
                     " ");
            break;
        case MENU_ENUM_LABEL_CHEAT_ADD_NEW_TOP:
            snprintf(s, len,
                     " ");
            break;
        case MENU_ENUM_LABEL_CHEAT_RELOAD_CHEATS:
            snprintf(s, len,
                     " ");
            break;
        case MENU_ENUM_LABEL_CHEAT_ADD_NEW_BOTTOM:
            snprintf(s, len,
                     " ");
            break;
        case MENU_ENUM_LABEL_CHEAT_DELETE_ALL:
            snprintf(s, len,
                     " ");
            break;
        case MENU_ENUM_LABEL_CHEAT_BIG_ENDIAN:
            snprintf(s, len,
                     "Big endian    : 258 = 0x0102\n"
                     "Little endian : 258 = 0x0201");
            break;
        case MENU_ENUM_LABEL_HOLD_FAST_FORWARD:
            snprintf(s, len,
                     "Hold for fast-forward. Releasing button \n"
                             "disables fast-forward.");
            break;
        case MENU_ENUM_LABEL_SLOWMOTION_HOLD:
            snprintf(s, len,
                     "Hold for slowmotion.");
            break;
        case MENU_ENUM_LABEL_FRAME_ADVANCE:
            snprintf(s, len,
                     "Frame advance when content is paused.");
            break;
        case MENU_ENUM_LABEL_BSV_RECORD_TOGGLE:
            snprintf(s, len,
                     "Toggle between recording and not.");
            break;
        case MENU_ENUM_LABEL_L_X_PLUS:
        case MENU_ENUM_LABEL_L_X_MINUS:
        case MENU_ENUM_LABEL_L_Y_PLUS:
        case MENU_ENUM_LABEL_L_Y_MINUS:
        case MENU_ENUM_LABEL_R_X_PLUS:
        case MENU_ENUM_LABEL_R_X_MINUS:
        case MENU_ENUM_LABEL_R_Y_PLUS:
        case MENU_ENUM_LABEL_R_Y_MINUS:
            snprintf(s, len,
                     "Axis for analog stick (DualShock-esque).\n"
                             " \n"
                             "Bound as usual, however, if a real analog \n"
                             "axis is bound, it can be read as a true analog.\n"
                             " \n"
                             "Positive X axis is right. \n"
                             "Positive Y axis is down.");
            break;
        case MENU_ENUM_LABEL_VALUE_WHAT_IS_A_CORE_DESC:
            snprintf(s, len,
                     "RetroArch by itself does nothing. \n"
                            " \n"
                            "To make it do things, you need to \n"
                            "load a program into it. \n"
                            "\n"
                            "We call such a program 'Libretro core', \n"
                            "or 'core' in short. \n"
                            " \n"
                            "To load a core, select one from\n"
                            "'Load Core'.\n"
                            " \n"
#ifdef HAVE_NETWORKING
                    "You can obtain cores in several ways: \n"
                    "* Download them by going to\n"
                    "'%s' -> '%s'.\n"
                    "* Manually move them over to\n"
                    "'%s'.",
                    msg_hash_to_str(MENU_ENUM_LABEL_VALUE_ONLINE_UPDATER),
                    msg_hash_to_str(MENU_ENUM_LABEL_VALUE_CORE_UPDATER_LIST),
                    msg_hash_to_str(MENU_ENUM_LABEL_VALUE_LIBRETRO_DIR_PATH)
#else
                            "You can obtain cores by\n"
                            "manually moving them over to\n"
                            "'%s'.",
                     msg_hash_to_str(MENU_ENUM_LABEL_VALUE_LIBRETRO_DIR_PATH)
#endif
            );
            break;
        case MENU_ENUM_LABEL_VALUE_HELP_CHANGE_VIRTUAL_GAMEPAD_DESC:
            snprintf(s, len,
                     "You can change the virtual gamepad overlay\n"
                             "by going to '%s' -> '%s'."
                             " \n"
                             "From there you can change the overlay,\n"
                             "change the size and opacity of the buttons, etc.\n"
                             " \n"
                             "NOTE: By default, virtual gamepad overlays are\n"
                             "hidden when in the menu.\n"
                             "If you'd like to change this behavior,\n"
                             "you can set '%s' to false.",
                     msg_hash_to_str(MENU_ENUM_LABEL_VALUE_SETTINGS),
                     msg_hash_to_str(MENU_ENUM_LABEL_VALUE_OVERLAY_SETTINGS),
                     msg_hash_to_str(MENU_ENUM_LABEL_VALUE_INPUT_OVERLAY_HIDE_IN_MENU)
            );
            break;
        case MENU_ENUM_LABEL_VALUE_VIDEO_MESSAGE_BGCOLOR_ENABLE:
            snprintf(s, len,
                     "Enables a background color for the OSD.");
            break;
        case MENU_ENUM_LABEL_VALUE_VIDEO_MESSAGE_BGCOLOR_RED:
            snprintf(s, len,
                     "Sets the red value of the OSD background color. Valid values are between 0 and 255.");
            break;
        case MENU_ENUM_LABEL_VALUE_VIDEO_MESSAGE_BGCOLOR_GREEN:
            snprintf(s, len,
                     "Sets the green value of the OSD background color. Valid values are between 0 and 255.");
            break;
        case MENU_ENUM_LABEL_VALUE_VIDEO_MESSAGE_BGCOLOR_BLUE:
            snprintf(s, len,
                     "Sets the blue value of the OSD background color. Valid values are between 0 and 255.");
            break;
        case MENU_ENUM_LABEL_VALUE_VIDEO_MESSAGE_BGCOLOR_OPACITY:
            snprintf(s, len,
                     "Sets the opacity of the OSD background color. Valid values are between 0.0 and 1.0.");
            break;
        case MENU_ENUM_LABEL_VALUE_VIDEO_MESSAGE_COLOR_RED:
            snprintf(s, len,
                     "Sets the red value of the OSD text color. Valid values are between 0 and 255.");
            break;
        case MENU_ENUM_LABEL_VALUE_VIDEO_MESSAGE_COLOR_GREEN:
            snprintf(s, len,
                     "Sets the green value of the OSD text color. Valid values are between 0 and 255.");
            break;
        case MENU_ENUM_LABEL_VALUE_VIDEO_MESSAGE_COLOR_BLUE:
            snprintf(s, len,
                     "Sets the blue value of the OSD text color. Valid values are between 0 and 255.");
            break;
        case MENU_ENUM_LABEL_MIDI_DRIVER:
            snprintf(s, len,
                     "MIDI driver to use.");
            break;
        case MENU_ENUM_LABEL_MIDI_INPUT:
            snprintf(s, len,
                     "Sets the input device (driver specific).\n"
                     "When set to \"Off\", MIDI input will be disabled.\n"
                     "Device name can also be typed in.");
            break;
        case MENU_ENUM_LABEL_MIDI_OUTPUT:
            snprintf(s, len,
                     "Sets the output device (driver specific).\n"
                     "When set to \"Off\", MIDI output will be disabled.\n"
                     "Device name can also be typed in.\n"
                     " \n"
                     "When MIDI output is enabled and core and game/app support MIDI output,\n"
                     "some or all sounds (depends on game/app) will be generated by MIDI device.\n"
                     "In case of \"null\" MIDI driver this means that those sounds won't be audible.");
            break;
        case MENU_ENUM_LABEL_MIDI_VOLUME:
            snprintf(s, len,
                     "Sets the master volume of the output device.");
            break;
        default:
            if (string_is_empty(s))
                strlcpy(s, msg_hash_to_str(MENU_ENUM_LABEL_VALUE_NO_INFORMATION_AVAILABLE), len);
            return -1;
    }

    return 0;
}
#endif

#ifdef HAVE_MENU
static const char *menu_hash_to_str_chs_label_enum(enum msg_hash_enums msg)
{
   if (msg <= MENU_ENUM_LABEL_INPUT_HOTKEY_BIND_END &&
         msg >= MENU_ENUM_LABEL_INPUT_HOTKEY_BIND_BEGIN)
   {
      static char hotkey_lbl[128] = {0};
      unsigned idx = msg - MENU_ENUM_LABEL_INPUT_HOTKEY_BIND_BEGIN;
      snprintf(hotkey_lbl, sizeof(hotkey_lbl), "input_hotkey_binds_%d", idx);
      return hotkey_lbl;
   }

   switch (msg)
   {
#include "msg_hash_lbl.h"
      default:
#if 0
         RARCH_LOG("Unimplemented: [%d]\n", msg);
#endif
         break;
   }

   return "null";
}
#endif

const char *msg_hash_to_str_chs(enum msg_hash_enums msg) {
#ifdef HAVE_MENU
    const char *ret = menu_hash_to_str_chs_label_enum(msg);

    if (ret && !string_is_equal(ret, "null"))
       return ret;
#endif

    switch (msg) {
#include "msg_hash_chs.h"
        default:
#if 0
            RARCH_LOG("Unimplemented: [%d]\n", msg);
            {
               RARCH_LOG("[%d] : %s\n", msg - 1, msg_hash_to_str(((enum msg_hash_enums)(msg - 1))));
            }
#endif
            break;
    }

    return "null";
}
