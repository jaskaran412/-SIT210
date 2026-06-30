let threshold = 50;

// --- Helper functions ---
function parseReading(payload) {
    let matches = String(payload).match(/([\d.]+)/);
    return matches ? parseFloat(matches[1]) : NaN;
}

function isValidReading(value) {
    return !isNaN(value);
}

function createAlertMessage(reading, threshold) {
    return {
        topic: "Sensor Alert!",
        payload: `⚠ Warning! Light sensor reading is ${reading} lx, above threshold of ${threshold} lx.`
    };
}

function createNormalMessage(reading, threshold) {
    return {
        topic: "Sensor Update",
        payload: `Light level normal: ${reading} lx (threshold: ${threshold} lx).`
    };
}

// --- Main logic ---
let reading = parseReading(msg.payload);

if (!isValidReading(reading)) {
    node.warn(`Invalid reading: ${msg.payload}`);
    return null;
}

msg.reading = reading;

if (reading > threshold) {
    node.warn("Sending email alert...");
    return createAlertMessage(reading, threshold);
} else {
    return createNormalMessage(reading, threshold);
}
