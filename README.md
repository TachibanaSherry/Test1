# Test1
program/
    server/                 后端
        common/
            Graph.h         待实现！图结构的头文件
            json_load.cpp   用于读取json文件的相关函数
            json.cpp        引入的json库
            trip_modules.h  基础结构体定义 模块类声明
        data/
            Dataset.json    自用小数据集，内容待商榷
        modules/            模块实现（1，3，4已粗略实现
            1_place
            2_itinerary     待实现！
            3_traffic
            4_food
            5_intergration  待实现！
    web/                    待实现！前端
        index.html
        style.css
        script.js