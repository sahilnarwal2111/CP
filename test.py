import pandas as pd
import numpy as np

# Example: Simulated canal level data at 30m intervals
data = {
    "Distance (m)": np.arange(0, 300, 30),  # Adjust as per your range
    "Canal Level": np.random.uniform(50, 100, 10)  # Sample levels
}

df = pd.DataFrame(data)
print(df)
# Convert 30m to 100ft (30.48m) and interpolate
new_distances = np.arange(0, df["Distance (m)"].max(), 30.48)
df_interp = pd.DataFrame({
    "Distance (m)": new_distances,
    "Canal Level": np.interp(new_distances, df["Distance (m)"], df["Canal Level"])
})

print(df_interp)
