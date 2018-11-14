
from refl1d.names import *
from copy import copy

# === Data files ===
# old-style loader for reflpak data:
# instrument template, load s1, s2, sample_width, and sample broadening
# sample_broadening = FWHM - 0.5*(s1+s2)/(d1-d2)
# for NG1, d1 = 1905 mm, d2 = 355.6 mm
# instrument = NCNR.NG1(Tlo=0.5, slits_at_Tlo=0.2, slits_below=0.2) 

# probe object combines instrument and data

#probe = load4('', back_reflectivity=False)
xs_probes = [Probe(T=numpy.linspace(0.0022797, 2.2803, 251), L=5.0000) for xs in range(4)]
probe = PolarizedNeutronProbe(xs_probes, Aguide=270.00, H=0.0000)

    
# === Stack ===
# the roughnesses of each layer are set to zero to begin with

s = Stack()
slds = []
slabs = []

slds.append(SLD(name='layer0', rho=4.0000, irho=100.00))
slabs.append(slds[0](0.0000, 10.000, magnetism=Magnetism(rhoM=0.0000, thetaM=90.000)))
s.add( slabs[0])

slds.append(SLD(name='layer1', rho=2.0000, irho=200.00))
slabs.append(slds[1](300.00, 11.000, magnetism=Magnetism(rhoM=1.0000, thetaM=900.00)))
s.add( slabs[1])

slds.append(SLD(name='layer2', rho=6.0000, irho=300.00))
slabs.append(slds[2](200.00, 22.000, magnetism=Magnetism(rhoM=2.0000, thetaM=1800.0)))
s.add( slabs[2])

slds.append(SLD(name='layer3', rho=6.0000, irho=300.00))
slabs.append(slds[3](0.0000, 22.000, magnetism=Magnetism(rhoM=2.0000, thetaM=1800.0)))
s.add( slabs[3])

slds.append(SLD(name='layer4', rho=0.0000, irho=400.00))
slabs.append(slds[4](0.0000, 0.0000, magnetism=Magnetism(rhoM=0.0000, thetaM=90.000)))
s.add( slabs[4])
    
# === Constraints ===
# thickness, interface (roughness) etc. are parameters and
# can be constrained, e.g.
# s[0].thickness = s[2].thickness

# inD2O[0].interface = inair[0].interface
# (to tie the first layer to have exactly the same thickness as the third layer)

# NB - list and array counting in python starts at zero!

# === Fit parameters ===
# "range" specifies a fitting range in terms of min/max value
# "pmp" specifices fitting range in terms of +/-  %
# "pm" specifies fitting range in terms of +/- value

# THETA OFFSET
# this parameter accounts for theta misalignment
# probe.theta_offset.range(-.01,.01)

# INTENSITY: check to see if cross-section is included in the probe defined by data files;
# if so, set the intensity for that cross-section to be equal to the pp intensity
if hasattr(probe, 'pm'): probe.pm.intensity = probe.pp.intensity
if hasattr(probe, 'mp'): probe.mp.intensity = probe.pp.intensity
if hasattr(probe, 'mm'): probe.mm.intensity = probe.pp.intensity
probe.pp.intensity.range(0.9,1.1)
probe.pp.intensity.value = 1.0

# DISABLE CROSS-SECTIONS
# probe.xs[1] = None # disables PM
# probe.xs[2] = None # disables MP

# LAYER RHOs
s[0].material.rho.range(3.0000, 5.0000)
s[1].material.rho.range(1.0000, 3.0000)
s[2].material.rho.range(5.0000, 7.0000)
s[3].material.rho.range(5.0000, 7.0000)
s[4].material.rho.range(-1.0000, 1.0000)

# LAYER RHOMs
s[0].magnetism.rhoM.range(-1.0000, 1.0000)
s[1].magnetism.rhoM.range(0.0000, 2.0000)
s[2].magnetism.rhoM.range(1.0000, 3.0000)
s[3].magnetism.rhoM.range(1.0000, 3.0000)
s[4].magnetism.rhoM.range(-1.0000, 1.0000)

# LAYER THETAMs
s[0].magnetism.rhoM.range(60.000, 120.00)
s[1].magnetism.rhoM.range(870.00, 930.00)
s[2].magnetism.rhoM.range(1770.0, 1830.0)
s[3].magnetism.rhoM.range(1770.0, 1830.0)
s[4].magnetism.rhoM.range(60.000, 120.00)

# LAYER THICKNESSES
s[0].thickness.range(0.0000, 100.00)
s[1].thickness.range(200.00, 400.00)
s[2].thickness.range(100.00, 300.00)
s[3].thickness.range(0.0000, 100.00)
s[4].thickness.range(0.0000, 100.00)

# LAYER ROUGHNESSES
s[0].interface.range(0.0000, 20.000)
s[1].interface.range(1.0000, 21.000)
s[2].interface.range(12.000, 32.000)
s[3].interface.range(12.000, 32.000)

# === Problem definition ===
# a model object consists of a sample and a probe,
# zed is the step size in Angstroms to be used for rendering the profile
# increase zed to speed up the calculation
zed = 1    

# step = True corresponds to a calculation of the reflectivity from an actual profile
# with microslabbed interfaces.  When step = False, the Nevot-Croce
# approximation is used to account for roughness.  This approximation speeds up
# the caclulation tremendously, and is reasonably accuarate as long as the
# roughness is much less than the layer thickness
step = False

model = Experiment(sample=s, probe=probe, dz=zed, step_interfaces = step)
## simultaneous fitting: if you define two models
## models = model1, model2
## problem = MultiFitProblem(models=models)

# fitting a single model:
problem = FitProblem(model)

problem.name = ""
