async function simulateBruteForce() {
    const inputField = document.getElementById('room-code-input');
    
    for (let i = 1000; i <= 9999; i++) {
        inputField.value = i; 
        console.log(`Testing Code: ${i}`);
        window.joinRoom();
        await new Promise(r => setTimeout(r, 100));
    }
}
simulateBruteForce();