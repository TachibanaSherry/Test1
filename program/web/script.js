// 读取本地JSON文件并展示行程
async function loadPlan() {
    try {
        const response = await fetch("data.json");
        const data = await response.json();

        // 填充总览数据
        document.getElementById('total_time').textContent = data.total_time;
        document.getElementById('total_cost').textContent = data.total_cost;

        // 填充行程表格
        const table = document.getElementById('schedule_table');
        // 清空原有行（保留表头）
        while (table.rows.length > 1) {
            table.deleteRow(1);
        }
        // 添加新行
        data.schedule.forEach(item => {
            const row = table.insertRow();
            row.insertCell().textContent = item.place;
            row.insertCell().textContent = item.visit_time;
            row.insertCell().textContent = item.transport;
            row.insertCell().textContent = item.restaurant;
        });
    } catch (error) {
        alert("读取行程数据失败,请先运行后端程序生成data.json文件");
    }
}
