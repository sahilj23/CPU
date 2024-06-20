document.addEventListener('DOMContentLoaded', () => {
    const schedulerForm = document.getElementById('schedulerForm');
    const addProcessButton = document.getElementById('addProcessButton');
    const results = document.getElementById('results');

    if (schedulerForm) {
        schedulerForm.addEventListener('submit', async function (e) {
            e.preventDefault();

            console.log('Form submitted');

            const algorithm = document.getElementById('algorithm').value;
            const timeQuantum = document.getElementById('timeQuantum').value || 0;
            const processes = Array.from(document.querySelectorAll('.process')).map(process => {
                return {
                    id: process.querySelector('.id').value,
                    burstTime: process.querySelector('.burstTime').value,
                    arrivalTime: process.querySelector('.arrivalTime').value,
                    priority: process.querySelector('.priority').value,
                    remainingTime: process.querySelector('.remainingTime').value || 0
                };
            });

            console.log('Collected data:', { algorithm, timeQuantum, processes });

            try {
                const response = await fetch('http://localhost:8080/schedule', {
                    method: 'POST',
                    headers: { 'Content-Type': 'application/json' },
                    body: JSON.stringify({ algorithm, timeQuantum, processes })
                });

                if (!response.ok) {
                    throw new Error(`HTTP error! status: ${response.status}`);
                }

                const result = await response.json();
                console.log('Received result:', result);

                if (results) {
                    results.textContent = result.output;
                }
            } catch (error) {
                console.error('Error:', error);
                if (results) {
                    results.textContent = `Error: ${error.message}`;
                }
            }
        });
    }

    if (addProcessButton) {
        addProcessButton.addEventListener('click', addProcess);
    }
});

let processCount = 1;

function addProcess() {
    processCount++;
    const processDiv = document.createElement('div');
    processDiv.classList.add('process');
    processDiv.innerHTML = `
        <label for="processId${processCount}">ID:</label>
        <input type="text" id="processId${processCount}" name="processId${processCount}" class="id" required><br>
        <label for="burstTime${processCount}">Burst Time:</label>
        <input type="number" id="burstTime${processCount}" name="burstTime${processCount}" class="burstTime" min="1" required><br>
        <label for="arrivalTime${processCount}">Arrival Time:</label>
        <input type="number" id="arrivalTime${processCount}" name="arrivalTime${processCount}" class="arrivalTime" min="0" required><br>
        <label for="priority${processCount}">Priority:</label>
        <input type="number" id="priority${processCount}" name="priority${processCount}" class="priority" min="1" required><br>
        <label for="remainingTime${processCount}">Remaining Time:</label>
        <input type="number" id="remainingTime${processCount}" name="remainingTime${processCount}" class="remainingTime" min="0"><br>
    `;
    document.getElementById('processes').appendChild(processDiv);
}
